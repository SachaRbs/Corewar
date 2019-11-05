/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:34 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 18:53:02 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_sti(t_vm *vm, t_proc *proc)
{
	int pc;
	int address;

	pc = mod_address(proc->pc);
	address = pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD);
	writing_mem(vm, address, 4, proc->reg[proc->arg_v[0]]);
	return (NULL);
}
