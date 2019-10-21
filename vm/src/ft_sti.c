/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:34 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 15:09:41 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_sti(t_vm *vm, t_proc *proc)
{
	// vm->mem[(proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD)) % MEM_SIZE] = proc->reg[proc->arg_v[0]];
	writing_mem(vm, (proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD)) % MEM_SIZE, REG_SIZE, proc->reg[proc->arg_v[0]]);
	return (NULL);
}