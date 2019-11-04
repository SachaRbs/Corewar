/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:35:52 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/04 12:15:49 by epham            ###   ########.fr       */
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
	ft_printf(BOLDWHITE"%s: ", p->file);
	ft_printf(BOLDRED"LEXICAL ERROR"RESET);
	ft_printf(BOLDWHITE" at [%d:%d]\n"RESET, p->row, p->col);
}

int		ft_lexerror(t_asm *p)
{
	if (p->champ)
		ft_strdel(&p->champ);
	if (p->comment)
		ft_strdel(&p->comment);
	if (p->str)
		ft_strdel(&p->str);
	free_tokens(p->tokens);
	print_error(p);
	exit(1);
}
