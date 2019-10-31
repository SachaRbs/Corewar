/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:35:52 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/31 19:41:18 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	print_error(t_asm *p)
{
	char	*err_buffer;
	int		i;

	i = 0;
	err_buffer = ft_strnew(p->col + 11);
	printf(BOLDWHITE"%s: ", p->file);
	printf(BOLDRED"LEXICAL ERROR"RESET);
	printf(BOLDWHITE" at %d:%d\n", p->row, p->col);
	printf(RESET"          ");
	printf(RESET"%s", p->line);
	while (i < p->col + 10)
	{
		err_buffer[i] = ' ';
		i++;
	}
	err_buffer[i] = '^';
	printf(RED"%s\n"RESET, err_buffer);
	ft_strdel(&err_buffer);
	// printf(RED"%*s\n"RESET, 1 + p->col + 10, "^");
}

int		ft_lexerror(t_asm *p)
{
	print_error(p);
	free_asm(p);
	exit(1);
}
