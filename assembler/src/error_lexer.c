/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:35:52 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/30 17:36:11 by yoribeir         ###   ########.fr       */
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
	printf(BOLDWHITE"%s: ", p->file);
	printf(BOLDRED"LEXICAL ERROR"RESET);
	printf(BOLDWHITE" at [%d:%d]\n", p->row, p->col);
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
