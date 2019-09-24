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

int		is_whitespace(int c)
{
	return (c == '\t' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

int		get_champion(t_asm *p, char *str)
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
                    return (0);
            }
            p->champ = ft_strsub(str, 0, end - str);
            printf("champ:[%s]\n", p->champ);
            return(1);
        }
    return (0);
}

int     get_comment(t_asm *p, char *str)
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
                return (0);
        }
        p->comment = ft_strsub(str, 0, end - str);
        printf("comment:[%s]\n\n", p->comment);
        return (1);
    }
    return (0);
}
