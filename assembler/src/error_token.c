/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:28:58 by epham             #+#    #+#             */
/*   Updated: 2019/10/29 18:49:43 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_error(t_asm *env, t_token *token)
{
	if (token->type == OP)
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
	}
	else if (token->type == DIRECT_LABEL || token->type == IND_LABEL)
	{
		printf("%s:%d:%d: Undeclared label \"%s\" used\n"
		, env->file, token->row, token->col, token->str);
	}
	else
	{
		printf("%s:%d:%d: Unexpected argument of type %d, value %s\n"
		, env->file, token->row, token->col, token->type, token->str);
	}
	return (-1);
}
