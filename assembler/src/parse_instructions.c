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

#include "../includes/asm.h"

int		indstrstr(const char *str, const char *find)
{
	int		i;
	int		y;
	int		ret;

	ret = -1;
	if (!(find[0]))
		return (-1);
	i = 0;
	while (str[i])
	{
		y = 0;
		while (find[y] == str[i + y] && find[y])
		{
			if (find[y + 1] == '\0')
				return (i);
			y++;
		}
		i++;
	}
	return (-1);
}


int     is_instruction(char *line)
{
    int     i;

    i = 0;
    while (g_op_tab[i].name)
    {
        if(!ft_strcmp(g_op_tab[i].name, line))
            return (i);
        i++;
    }
    return (0);
}

// int		is_instruction(char *line)
// {
// 	int		i;
// 	int		ret;

// 	i = 0;
// 	while (g_op_tab[i].name)
// 	{
// 		ret = indstrstr(line, g_op_tab[i].name);
// 		if (ret != -1 && ft_strlen(line) == ft_strlen(g_op_tab[i].name))
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

int		check_instruction(t_asm *p, char **line, int size)
{
	char	*str;

	(void)p;
	str = ft_strndup(*line, size);
	if (is_instruction(str))
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
