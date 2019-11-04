/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:55 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/01 18:53:37 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <limits.h>

#define STR (p->line + p->col)

unsigned int	ft_nblen(long n)
{
	unsigned int	count;

	count = 1;
	while (n /= 10)
		count++;
	return (count);
}

void	parse_content(t_asm *p, t_token *token, int start, size_t len)
{
	size_t	size;
	size_t	str_len;

	if (token->type == IND_LABEL)
		token->str = ft_strsub(p->line, start + 1, len - 1);
	else if (token->type == DIRECT)
	{
		token->str = ft_strsub(p->line, start, len);
		str_len = ft_strlen(token->str);
		token->value = ft_atol(p->line + start);
		size = token->str[0] == '-' ? str_len - 1 : str_len;
		if (size != ft_nblen(token->value)
		|| token->value > UINT_MAX
		|| token->value < INT_MIN)
			ft_lexerror(p);
	}
	else
		token->str = ft_strsub(p->line, start, len);
}

void	parse_digits(t_asm *p, t_token *new, int start)
{
	int		size;

	size = start;
	if (p->line[p->col] == '-')
		p->col++;
	while (ft_isdigit(p->line[p->col]))
		p->col++;
	if ((p->col > size) && (is_divider(p->line[p->col]) || new->type == DIRECT))
	{
		parse_content(p, new, start, p->col - start);
		add_token(&p->tokens, new);
	}
	else if (new->type != DIRECT)
	{
		p->col = start;
		parse_symbol(p, new, start);
	}
	else
		ft_lexerror(p);

}

void	parse_symbol(t_asm *p, t_token *new, int start)
{
	int		size;

	size = p->col;
	while (ft_strchr(LABEL_CHARS, p->line[p->col]))
		p->col++;
	if (p->line[p->col] == LABEL_CHAR && (p->col > size) && p->col++)
	{
		parse_content(p, new, size, p->col - size - 1);
		new->type = LABEL;
		add_token(&p->tokens, new);
	}
	else if ((p->col > size) && is_divider(p->line[p->col]))
	{
		parse_content(p, new, start, p->col - start);
		if (*new->str == '.')
			parse_header(p, new);
		if (new->type == INDEX)
			new->type = is_reg(p, new->str) ? REGISTER : OP;
		if (new->type == OP)
			fill_optoken(new);
		add_token(&p->tokens, new);
	}
	else
		ft_lexerror(p);
}

void	parse_token(t_asm *p)
{
	if ((p->line)[p->col] == SEPARATOR_CHAR && ++p->col)
		add_token(&p->tokens, init_token(p, SEPARATOR));
	else if ((p->line)[p->col] == '\n' && ++p->col)
		add_token(&p->tokens, init_token(p, NEWLINE));
	else if ((p->line)[p->col] == '.')
		parse_symbol(p, init_token(p, NAME), p->col++);
	else if ((p->line)[p->col] == DIRECT_CHAR && ++p->col)
	{
		if ((p->line)[p->col] == LABEL_CHAR && ++p->col)
			parse_symbol(p, init_token(p, DIRECT_LABEL), p->col);
		else
			parse_digits(p, init_token(p, DIRECT), p->col);
	}
	else if ((p->line)[p->col] == LABEL_CHAR)
		parse_symbol(p, init_token(p, IND_LABEL), p->col++);
	else
		parse_digits(p, init_token(p, INDEX), p->col);

}

void	parse(t_asm *p)
{
	while ((ft_readline(p->fd, &p->str, &p->line) > 0))
	{
		p->col = 0;
		while(p->line[p->col])
		{
			skip_whitespaces(p, p->line);
			skip_comment(p, p->line);
			if (p->line[p->col])
				parse_token(p);
		}
    	p->row++;
		ft_strdel(&p->line);
	}
	ft_strdel(&p->line);
	printf(GRN"%s\n"RESET, p->champ);
	printf(GRN"%s\n"RESET, p->comment);
	print_token(p->tokens);
	if (check_token(p) == -1)
		exit(1);
}