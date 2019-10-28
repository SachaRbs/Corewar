/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:10:56 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/17 17:49:22 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	parse_champion(t_asm *p, char *line)
{
	size_t		start;

	start = 0;
    while (is_whitespace(line[p->col]) && line[p->col])
        p->col++;
    if (line[p->col] == '"')
    {
        p->col++;
		start = p->col;
		// NEEDS TO READ LINE UNTIL NEXT QUOTE
		while (line[p->col] != '"')
			p->col++;
    }
    p->champ = ft_strsub(line + start, 0, p->col - start);
    if (ft_strlen(p->champ) > PROG_NAME_LENGTH)
        ft_error("CHAMPION NAME TOO LONG");
}

void	parse_comment(t_asm *p, char *line)
{
	size_t		start;

	start = 0;
    while (is_whitespace(line[p->col]) && line[p->col])
        p->col++;
    if (line[p->col] == '"')
    {
        p->col++;
		start = p->col;
		// NEEDS TO READ LINE UNTIL NEXT QUOTE
		while (line[p->col] && line[p->col] != '"')
			p->col++;
    }
    p->comment = ft_strsub(line + start, 0, p->col - start);
    if (ft_strlen(p->comment) > COMMENT_LENGTH)
        ft_error("CHAMPION COMMENT TOO LONG");
}

void	parse_header(t_asm *p, t_token *new, char *line)
{
	if (!ft_strncmp(new->str, NAME_CMD_STRING, 5))
	{
		if (p->champ && new->type == NAME)
			ft_error("HEADER ALREADY EXISTS");
		new->type = NAME;
		parse_champion(p, line);
		if (line[p->col] == '"')
			p->col++;
	}
	else if (!ft_strncmp(new->str, COMMENT_CMD_STRING, 8))
	{
		if (p->comment && new->type == COMMENT)
			ft_error("HEADER ALREADY EXISTS");
		new->type = COMMENT;
		parse_comment(p, line);
		if (line[p->col] == '"')
			p->col++;
	}
	else
		ft_error("BAD COMMAND");
}
