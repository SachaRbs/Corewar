/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:27:06 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/25 17:27:06 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int     is_instruction(t_asm *p, char *line)
{
    int     i;

    i = 0;
    while (p->op_tab[i].name)
    {
        if(!ft_strcmp(p->op_tab[i].name, line))
            return (i);
        i++;
    }
    return (0);
}

int		check_instruction(t_asm *p, char **line, int size)
{
    char    *str;

    str = ft_strndup(*line, size);
    if (is_instruction(p, str))
    {
        printf(RED "%s\n" RESET, str);
        return (1);
    }
    else
    {
        printf("INSTRUCTION: [%s] NOT VALID\n", *line);
        return (0);
    }
}
