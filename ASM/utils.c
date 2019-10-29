/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:06:54 by anonymous         #+#    #+#             */
/*   Updated: 2019/09/10 16:00:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int		ft_lexerror(t_asm *p)
{
	printf("Lexical error at [%d:%d]\n", p->row, p->col + 1);
	exit(1);
}

int		is_reg(char *line)
{
	int		i;
	int		reg;

	i = 0;
	if (line[i++] == 'r')
	{
		reg = ft_atoi(line + i);
		if (reg <= REG_NUMBER && reg > 0)
			return (1);
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
