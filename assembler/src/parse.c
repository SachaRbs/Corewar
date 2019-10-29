/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:55 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/29 19:23:02 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

#define STR (*line + p->col)

void	parse_content(t_token *token, char *line, int start, size_t len)
{
	if (token->type == IND_LABEL)
		token->str = ft_strsub(line, start + 1, len - 1);
	else
		token->str = ft_strsub(line, start, len);
}

void	parse_digits(t_asm *p, t_token *new, char **line, int start)
{
	int		size;

	// printf(CYN"[%s]\n"RESET, *line + p->col);
	size = start;
	if ((*line)[p->col] == '-')
		p->col++;
	while (ft_isdigit((*line)[p->col]))
		p->col++;
	if ((p->col > size) && (is_divider((*line)[p->col]) || new->type == DIRECT))
	{
		parse_content(new, *line, start, p->col - start);
		add_token(&p->tokens, new);
	}
	else if (new->type != DIRECT)
	{
		p->col = start;
		parse_symbol(p, new, line, start);
	}
	else
		ft_lexerror(p);

}

void	parse_symbol(t_asm *p, t_token *new, char **line, int start)
{
	int		size;

	// printf(RED"[%s]\n"RESET, STR);
	size = p->col;
	while (ft_strchr(LABEL_CHARS, (*line)[p->col]))
		p->col++;
	if ((*line)[p->col] == LABEL_CHAR && (p->col > size) && p->col++)
	{
		parse_content(new, *line, size, p->col - size - 1);
		new->type = LABEL;
		add_token(&p->tokens, new);
	}
	else if ((p->col > size) && is_divider((*line)[p->col]))
	{
		parse_content(new, *line, start, p->col - start);
		if (*new->str == '.')
			parse_header(p, new, line);
		if (new->type == INDEX)
			new->type = is_reg(new->str) ? REGISTER : OP;
		if (new->type == OP)
			fill_optoken(new);
		add_token(&p->tokens, new);
	}
	else
		ft_lexerror(p);
}

void	parse_token(t_asm *p, char **line)
{
	if ((*line)[p->col] == SEPARATOR_CHAR && ++p->col)
		add_token(&p->tokens, init_token(p, SEPARATOR));
	else if ((*line)[p->col] == '\n' && ++p->col)
		add_token(&p->tokens, init_token(p, NEWLINE));
	else if ((*line)[p->col] == '.')
		parse_symbol(p, init_token(p, NAME), line, p->col++);
	else if ((*line)[p->col] == DIRECT_CHAR && ++p->col)
	{
		if ((*line)[p->col] == LABEL_CHAR && ++p->col)
			parse_symbol(p, init_token(p, DIRECT_LABEL), line, p->col);
		else
			parse_digits(p, init_token(p, DIRECT), line, p->col);
	}
	else if ((*line)[p->col] == LABEL_CHAR)
		parse_symbol(p, init_token(p, IND_LABEL), line, p->col++);
	else
		parse_digits(p, init_token(p, INDEX), line, p->col);

}

void	parse(t_asm *p)
{
	static char		*str;
	char 			*line;

	str = ft_strnew(1);
	while ((ft_readline(p->fd, &p->str, &line) > 0))
	{
		p->col = 0;
		while(line[p->col])
		{
			skip_whitespaces(p, line);
			skip_comment(p, line);
			if (line[p->col])
				parse_token(p, &line);
		}
    	p->row++;
	}
	if (!p->tokens)
		printf("NULL\n");
	print_token(p->tokens);
	check_token(p);
}
