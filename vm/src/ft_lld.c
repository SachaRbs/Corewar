/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:39 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/24 18:01:15 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_lld(t_vm *vm, t_proc *proc)
{
	int number;

	number = (proc->arg_t[0] == DIR_CODE) ? proc->arg_v[0] :
	read_mem(vm, proc->pc + (proc->arg_v[0]), 4, 0, proc);
	proc->reg[proc->arg_v[1]] = number;
	proc->carry = proc->reg[proc->arg_v[1]] ? 0 : 1;
	return (NULL);
} 

//wrong