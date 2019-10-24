/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:34 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/24 14:05:38 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_sti(t_vm *vm, t_proc *proc)
{
	int address;

	if (proc->pc < 0)
		proc->pc = MEM_SIZE + proc->pc;
	address = (proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD)) % MEM_SIZE;
	writing_mem(vm, address, 4, proc->reg[proc->arg_v[0]]);
	return (NULL);
}