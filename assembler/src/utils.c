/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:26:21 by epham             #+#    #+#             */
/*   Updated: 2019/11/04 12:26:23 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_reg(char *line, t_asm *p)
{
	int		i;
	int		reg;

	i = 0;
	if (line[i++] == 'r')
	{
		reg = ft_atoi(line + i);
		if (reg <= 16 && reg > 0)
			return (1);
		else
		{
			print_error(p);
			ft_error("Register value is out of bounds");
			free_asm(p);
			exit(1);
		}
	}
	return (0);
}

int		is_whitespace(int c)
{
	return (c == '\t' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

int		is_divider(int c)
{
	return (is_whitespace(c) ||
		c == ',' ||
		c == '\n' ||
		c == '"');
}

void	skip_whitespaces(t_asm *p, char *line)
{
	while (is_whitespace(line[p->col]))
		p->col++;
}

void	skip_comment(t_asm *p, char *line)
{
	if (line[p->col] == COMMENT_CHAR ||
		line[p->col] == ALT_COMMENT_CHAR)
		while (line[p->col] != '\n')
			p->col++;
}
