/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:28:36 by epham             #+#    #+#             */
/*   Updated: 2019/11/03 22:34:01 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ocp_3_direct(t_token *arg2)
{
	if (arg2->type == REGISTER)
		return (148);
	else if (arg2->type == DIRECT_LABEL || arg2->type == DIRECT)
		return (164);
	else
		return (180);
}

int			ocp_3_indirect(t_token *arg2)
{
	if (arg2->type == REGISTER)
		return (212);
	else if (arg2->type == DIRECT_LABEL || arg2->type == DIRECT)
		return (228);
	else
		return (244);
}

int			ocp_3_args(t_token *token)
{
	t_token *arg1;
	t_token *arg2;
	t_token *arg3;

	arg1 = token->next;
	arg2 = arg1->next->next;
	arg3 = arg2->next->next;
	if (arg1->type == REGISTER)
	{
		if (arg2->type == REGISTER)
			return (arg3->type == REGISTER ? 84 : 88);
		else if (arg2->type == DIRECT || arg2->type == DIRECT_LABEL)
			return (arg3->type == REGISTER ? 100 : 104);
		else if (arg2->type == INDEX || arg2->type == IND_LABEL)
			return (arg3->type == REGISTER ? 116 : 120);
	}
	else if (arg1->type == DIRECT || arg1->type == DIRECT_LABEL)
		return (ocp_3_direct(arg2));
	else if (arg1->type == INDEX || arg1->type == IND_LABEL)
		return (ocp_3_indirect(arg2));
	return (0);
}

int			ocp_2_args(t_token *token)
{
	t_token *arg;

	arg = token->next;
	if (arg->type == REGISTER)
		return (arg->next->next->type == REGISTER ? 80 : 112);
	else if (arg->type == DIRECT || arg->type == DIRECT_LABEL)
		return (144);
	else if (arg->type == INDEX || arg->type == IND_LABEL)
		return (208);
	return (0);
}

void		get_ocp(t_token **token)
{
	int		nb_arg;
	int		ret;

	ret = 0;
	nb_arg = g_op_tab[(*token)->op_index].nb_arg;
	if (nb_arg == 1)
		(*token)->ocp = 64;
	else if (nb_arg == 2)
		(*token)->ocp = ocp_2_args(*token);
	else if (nb_arg == 3)
		(*token)->ocp = ocp_3_args(*token);
}
