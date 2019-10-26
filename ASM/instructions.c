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

int		indstrstr(const char *str, const char *find)
{
	int		i;
	int		y;

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


int		is_instruction(char *line)
{
	int		i;
	int		inst;
	int		retstr;
	int		min;

	i = 0;
	inst = -1;
	retstr = -1;
	min = ft_strlen(line);
	while (g_op_tab[i].name)
	{
		retstr = indstrstr(line, g_op_tab[i].name);
		if (retstr != -1 && min >= retstr)
		{
			min = retstr;
			inst = i;
		}
		i++;
	}
	return (inst != ft_strlen(line) ? inst : -1);
}

int		check_instruction(t_asm *p, char **line, int size)
{
	char	*str;

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
