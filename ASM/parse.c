/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:55 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/23 17:56:43 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void	parse_symbol(t_asm *p, t_token *new, char **line)
{
	int		start;

	p->col++;
	start = p->col;
	while (ft_strchr(LABEL_CHARS, *(line[p->col])))
		p->col++;
	if (*(line[p->col]) == LABEL_CHAR)
	{
		new->str = ft_strsub(*line, start, p->col - start);
		new->type = LABEL;
		add_token(&p->tokens, new);
	}
	else if (*(line[p->col]) )
}

void	parse_token(t_asm *p, char **line)
{
	if (*(line[p->col]) == SEPARATOR_CHAR)
		add_token(&p->tokens, init_token(p, SEPARATOR));
	else if (*(line[p->col]) == '\n')
		add_token(&p->tokens, init_token(p, NEWLINE));
	else if (*(line[p->col]) == '.')
		parse_symbol(p, init_token(p, COMMAND), line);
	else if (*(line[p->col]) == LABEL_CHAR)
		parse_symbol(p, init_token(p, COMMAND), line);
}

void	parse(t_asm *p)
{
	static char		*str;
	char 			*line;

	str = ft_strnew(1);
	while ((ft_readline(p->fd, &p->str, &line) > 0))
	{
		p->col = 0;
		skip_whitespaces(&line);
		skip_comment(&line);
		if (line[p->col])
			parse_token(p, &line);
    	p->row++;
	}
}
