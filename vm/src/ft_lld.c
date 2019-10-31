/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:39 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/29 15:34:24 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

/*
***		WRONG ?
*/

void	*ft_lld(t_vm *vm, t_proc *proc)
{
	int number;

	number = (proc->arg_t[0] == DIR_CODE) ? proc->arg_v[0] :
	read_mem(vm, proc->pc + (proc->arg_v[0]), 4);
	proc->reg[proc->arg_v[1]] = number;
	proc->carry = proc->reg[proc->arg_v[1]] ? 0 : 1;
	return (NULL);
}
