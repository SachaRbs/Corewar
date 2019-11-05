/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:28:58 by epham             #+#    #+#             */
/*   Updated: 2019/11/05 21:02:21 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	syntax_error(t_asm *p, t_token *token, char *str)
{
	ft_printf(BOLDWHITE"%s: ", p->file);
	ft_printf(BOLDRED"SYNTAX ERROR"RESET);
	ft_printf(BOLDWHITE" %s", str);
	ft_printf(" at [%d:%d]\n"RESET, token->row, token->col);
}

int		op_error(t_asm *env, t_token *token)
{
	if (token->prev->type == LABEL || token->prev->type == NEWLINE)
		syntax_error(env, token, "Wrong syntax for operation");
	else
		syntax_error(env, token, "Unexpected operation token");
	return (-1);
}

int		incomplete_header(t_asm *env, t_token *token)
{
	if (!env->champ)
		syntax_error(env, token, "Incomplete header: missing name of champion");
	else
		syntax_error(env, token, "Incomplete header: missing comment");
	return (-1);
}

int		label_error(t_asm *env, t_token *token)
{
	syntax_error(env, token, "Undeclared label");
	return (-1);
}

int		get_error(t_asm *env, t_token *token)
{
	if (env->f_header == 0)
		incomplete_header(env, token);
	else if (!token)
		lexical_error(env, 8);
	else if (token->type == OP)
		op_error(env, token);
	else if (token->type == DIRECT_LABEL || token->type == IND_LABEL)
		label_error(env, token);
	else
		syntax_error(env, token, "Unexpected argument");
	free_asm(env);
	return (-1);
}
