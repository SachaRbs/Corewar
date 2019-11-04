/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:24:50 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/04 15:49:52 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_reg(t_asm *p, char *line)
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
			ft_lexerror(p);
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
		c == '"' ||
		c == DIRECT_CHAR ||
		c == COMMENT_CHAR ||
		c == ALT_COMMENT_CHAR);
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
