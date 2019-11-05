/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:27:06 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/05 21:02:54 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_instruction(char *line)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(g_op_tab[i].name, line))
			return (i);
		i++;
	}
	return (0);
}

int		check_instruction(t_asm *p, char **line, int size)
{
	char	*str;

	(void)p;
	str = ft_strndup(*line, size);
	if (is_instruction(str))
	{
		ft_printf(RED "%s\n" RESET, str);
		return (1);
	}
	else
	{
		ft_printf("INSTRUCTION: [%s] NOT VALID\n", *line);
		return (0);
	}
}
