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

#include "asm.h"

int		is_whitespace(int c)
{
	return (c == '\t' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

void	get_champion(t_asm *p, char *str)
{
    char    *end;

    if (!ft_strncmp(str, NAME_CMD_STRING, 5) && !p->champ)
    {
            str += 5;
            while (is_whitespace(*str) && *str)
                str++;
            if (*str == '"')
            {
                str++;
                if (!(end = ft_strchr(str, '"')))
                    ft_error("INVALID CHAMPION NAME");
            }
            p->champ = ft_strsub(str, 0, end - str);
            if (ft_strlen(p->champ) > PROG_NAME_LENGTH)
                ft_error("CHAMPION NAME TOO LONG");
            printf(GRN"[%s]\n"RESET, p->champ);
    }
}

void    get_comment(t_asm *p, char *str)
{
    char    *end;

    if (!ft_strncmp(str, COMMENT_CMD_STRING, 8) && !p->comment)
    {
        str += 8;
        while (is_whitespace(*str) && *str)
            str++;
        if (*str == '"')
        {
            str++;
            if (!(end = ft_strchr(str, '"')))
                ft_error("INVALID CHAMPION COMMENT");
        }
        p->comment = ft_strsub(str, 0, end - str);
        printf(GRN"[%s]\n\n"RESET, p->comment);
        if (ft_strlen(p->comment) > COMMENT_LENGTH)
            ft_error("CHAMPION COMMENT TOO LONG");
    }
}
