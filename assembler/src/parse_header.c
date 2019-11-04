/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:38:19 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/04 18:50:03 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	parse_multiline(t_asm *p, int flag)
{
	size_t	size;
	char	*str;
	char	*end;

	str = ft_strdup(p->line + p->col);
	ft_strdel(&p->line);
	while (ft_readline(p->fd, &p->str, &p->line) > 0
	&& (!(end = ft_strchr(p->line, '"'))))
	{
		str = ft_strjoindel(str, p->line);
		ft_strdel(&p->line);
		p->row++;
	}
	p->row++;
	size = ft_strlen(str);
	str = ft_strjoindel(str, p->line);
	p->col = 0;
	while ((p->line)[p->col] && (p->line)[p->col] != '"')
		p->col++;
	if (!flag)
		p->champ = ft_strsub(str, 0, p->col + size);
	else
		p->comment = ft_strsub(str, 0, p->col + size);
	ft_strdel(&str);
}

void	parse_champion(t_asm *p)
{
	size_t		start;

	start = 0;
	while (is_whitespace(p->line[p->col]) && p->line[p->col])
		p->col++;
	if (p->line[p->col] == '"')
	{
		p->col++;
		start = p->col;
		if (ft_strchr(p->line + p->col, '"'))
		{
			while (p->line[p->col] && p->line[p->col] != '"')
				p->col++;
			p->champ = ft_strsub(p->line + start, 0, p->col - start);
		}
		else
			parse_multiline(p, 0);
	}
	else
		lexical_error(p, 2);
	if (!p->champ || ft_strlen(p->champ) > PROG_NAME_LENGTH)
		lexical_error(p, 3);
}

void	parse_comment(t_asm *p)
{
	size_t		start;

	start = 0;
	while (is_whitespace(p->line[p->col]) && p->line[p->col])
		p->col++;
	if (p->line[p->col] == '"')
	{
		p->col++;
		start = p->col;
		if (ft_strchr(p->line + p->col, '"'))
		{
			while (p->line[p->col] && p->line[p->col] != '"')
				p->col++;
			p->comment = ft_strsub(p->line + start, 0, p->col - start);
		}
		else
			parse_multiline(p, 1);
	}
	else
		lexical_error(p, 2);
	if (!p->comment || ft_strlen(p->comment) > COMMENT_LENGTH)
		lexical_error(p, 4);
}

void	parse_header(t_asm *p, t_token *new)
{
	if (!ft_strncmp(new->str, NAME_CMD_STRING, 5))
	{
		if (p->champ && new->type == NAME)
			ft_error("HEADER ALREADY EXISTS");
		new->type = NAME;
		parse_champion(p);
		if (p->line[p->col] == '"')
			p->col++;
	}
	else if (!ft_strncmp(new->str, COMMENT_CMD_STRING, 8))
	{
		if (p->comment && new->type == COMMENT)
			ft_error("HEADER ALREADY EXISTS");
		new->type = COMMENT;
		parse_comment(p);
		if (p->line[p->col] == '"')
			p->col++;
	}
	else
		lexical_error(p, 5);
}
