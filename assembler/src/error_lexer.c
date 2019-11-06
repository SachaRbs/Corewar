/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:35:52 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/06 13:23:47 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_error(char *str)
{
	ft_printf(BOLDRED"ERROR "RESET);
	ft_printf(BOLDWHITE"%s\n", str);
	exit(1);
}

void	print_error(t_asm *p)
{
	ft_printf(BOLDWHITE"%s: ", p->file);
	ft_printf(BOLDRED"LEXICAL ERROR"RESET);
	ft_printf(BOLDWHITE" at [%d:%d]\n", p->row, p->col);
}

int		lexical_error(t_asm *p, int errcode)
{
	ft_printf(BOLDWHITE"%s: ", p->file);
	ft_printf(BOLDRED"LEXICAL ERROR "BOLDWHITE);
	if (errcode == 1)
		ft_printf("Token value overflows");
	if (errcode == 2)
		ft_printf("Unexpected character");
	if (errcode == 3)
		ft_printf("Wrong champion name");
	if (errcode == 4)
		ft_printf("Wrong comment name");
	if (errcode == 5)
		ft_printf("Wrong command");
	if (errcode == 6)
		ft_printf("Register value out of bounds");
	if (errcode == 7)
		ft_printf("Wrong Header");
	if (errcode == 8)
		ft_printf("No tokens");
	ft_printf(BOLDWHITE" at [%d:%d]\n"RESET, p->row, p->col);
	free_asm(p);
	exit(1);
}
