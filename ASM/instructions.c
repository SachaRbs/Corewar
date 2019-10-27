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

int		ft_isspace(char c)
{
	printf("CHAR : [%c]\n", c);
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f')
	{
		printf("isspace returns 0 for char [%c]\n", c);
		return (0);
	}
	printf("isspace returns -1 for char [%c]\n", c);
	return (-1);
}

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
			{
				printf("found %s\n", find);
				if (i != 0)
					printf("str[i - 1] : [%c]\n", str[i - 1]);	
				printf("str[i + y + 1] [%c]\n", str[i + y + 1]);				
				if ((i != 0 && printf("STR I - 1 : [%c]\n", str[i - 1]) && ft_isspace(str[i - 1]) == -1 
				&& (str[i + y + 1] && printf("STR I + Y + 1 : [%c]\n", str[i + y + 1]) && (ft_isspace(str[i + y + 1] == -1) && str[i + y + 1] != '%')))
				|| (i == 0 && (str[i + y + 1] && printf("STR I + Y + 1 : [%c]\n", str[i + y + 1]) && (ft_isspace(str[i + y + 1] == -1) && str[i + y + 1] != '%'))))
				{
					if (str[i + y + 1] && printf("STR I + Y + 1 : [%c]\n", str[i + y + 1]) && (ft_isspace(str[i + y + 1] == -1) && str[i + y + 1] != '%'))
						printf("not valid : char [%c]\n", str[i + y + 1]);
					ret = -1;
					i = i + y;
					y = -1;
				}
				else
					return (i);
				
			}
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
