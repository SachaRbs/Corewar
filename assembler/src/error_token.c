/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:28:58 by epham             #+#    #+#             */
/*   Updated: 2019/10/30 15:54:49 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		op_error(t_asm *env, t_token *token)
{
	if (token->prev->type == LABEL || token->prev->type == NEWLINE)
	{
		printf("%s:%d:%d: Wrong syntax for operation\n"
		, env->file, token->row, token->col);
	}
	else
	{
		printf("%s:%d:%d: Unexpected operation token\n"
		, env->file, token->row, token->col);
	}
	return (-1);
}

int		incomplete_header(t_asm *env, t_token *token)
{
	if (!env->champ)
		printf("%s:%d:%d: Incomplete header: missing name of champion\n"
		, env->file, token->row, token->col);
	else
		printf("%s:%d:%d: Incomplete header: missing comment\n"
		, env->file, token->row, token->col);
	return (-1);
}

int		label_error(t_asm *env, t_token *token)
{
	printf("%s:%d:%d: Undeclared label \"%s\"\n"
	, env->file, token->row, token->col, token->str);
	return (-1);
}

int		get_error(t_asm *env, t_token *token)
{
	if (env->f_header == 0)
		incomplete_header(env, token);
	else if (token->type == OP)
		op_error(env, token);
	else if (token->type == DIRECT_LABEL || token->type == IND_LABEL)
		label_error(env, token);
	else
	{
		printf("%s:%d:%d: Unexpected argument of type %d, value %s\n",
		env->file, token->row, token->col, token->type, token->str);
	}
	free_asm(env);
	return (-1);
}
