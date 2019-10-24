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

#include "includes/asm.h"

void	parse_champion(t_asm *p, char *line, char *end)
{
	line += 5;
    while (is_whitespace(*line) && *line)
        line++;
    if (*line == '"')
    {
        line++;
 		if (!(end = ft_strchr(line, '"')))
			ft_error("INVALID CHAMPION NAME");
    }
    p->champ = ft_strsub(line, 0, end - line);
    if (ft_strlen(p->champ) > PROG_NAME_LENGTH)
        ft_error("CHAMPION NAME TOO LONG");
    printf(GRN"%s\n"RESET, p->champ);
}

void	parse_comment(t_asm *p, char *line, char *end)
{
	line += 8;
    while (is_whitespace(*line) && *line)
        line++;
    if (*line == '"')
    {
        line++;
 		if (!(end = ft_strchr(line, '"')))
			ft_error("INVALID CHAMPION COMMENT");
    }
    p->comment = ft_strsub(line, 0, end - line);
    if (ft_strlen(p->comment) > COMMENT_LENGTH)
        ft_error("CHAMPION COMMENT TOO LONG");
    printf(GRN"%s\n"RESET, p->comment);
}

void	parse_header(t_asm *p, t_token *new, char *line)
{
	char	*end;

	end = NULL;
	if (!ft_strncmp(new->str, NAME_CMD_STRING, 5))
	{
		new->type = COMMAND;
		parse_champion(p, line, end);
	}
	if (!ft_strncmp(new->str, COMMENT_CMD_STRING, 8))
	{
		new->type = COMMAND;
		parse_comment(p, line, end);
	}
}
