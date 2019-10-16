/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:32:01 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 13:21:02 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_sub(t_vm *vm, t_proc *proc)
{
	// proc->arg_v[2] = proc->arg_v[0] - proc->arg_v[1];
	proc->reg[proc->arg_v[2]] = proc->arg_v[0] - proc->arg_v[1];
	if (proc->arg_v[2] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}