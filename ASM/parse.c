/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:55 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/24 17:43:04 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void	parse_symbol(t_asm *p, t_token *new, char **line)
{
	int		start;

	p->col++;
	printf(RED"%s\n"RESET, *line + p->col);
	start = p->col;

	while (ft_strchr(LABEL_CHARS, (*line)[p->col]))
		p->col++;
	printf(RED"%s\n"RESET, *line + p->col);
	if ((*line)[p->col] == LABEL_CHAR)
	{
		new->str = ft_strsub(*line, start, p->col - start);
		new->type = LABEL;
		add_token(&p->tokens, new);
	}
	else if ((p->col > start) > 0 && is_whitespace((*line)[p->col]))
	{
		printf("is_whitespace %d\n", start);
		new->str = ft_strsub(*line, start - 1, p->col - start + 1);
		printf("%s\n", new->str);
		if (!p->champ || !p->comment)
			parse_header(p, new, *line);
		add_token(&p->tokens, new);
	}
}

void	parse_token(t_asm *p, char **line)
{
	if ((*line)[p->col] == SEPARATOR_CHAR)
		add_token(&p->tokens, init_token(p, SEPARATOR));
	else if ((*line)[p->col] == '\n')
	{
		printf("newLINE\n");
		add_token(&p->tokens, init_token(p, NEWLINE));
	}
	else if ((*line)[p->col] == '.')
		parse_symbol(p, init_token(p, COMMAND_NAME), line);
	else if ((*line)[p->col] == LABEL_CHAR)
		parse_symbol(p, init_token(p, COMMAND_NAME), line);
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
		// skip_comment(&line);
		if (line[p->col])
			parse_token(p, &line);
    	p->row++;
	}
	if (!p->tokens)
		printf("NULL\n");
	print_token(p->tokens);
}
