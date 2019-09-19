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
    int     size;

    size = 0;
    if (!ft_strncmp(str, ".name", 4) && !p->champ)
        {
            str += 5;
            while (is_whitespace(*str))
                str++;
            printf("[%s]\n", str);
            if (*str == '"')
            {
                str++;
                while(str[size] != '"')
                    size++;
            }
            printf("%d", size);
            p->champ = ft_strsub(str, 0, size);
            printf("champ:[%s]\n", p->champ);
            printf("\n\n\n\n");
            return(1);
        }
    return (0);
}
