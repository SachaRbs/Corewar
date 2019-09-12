/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/09/12 12:37:27 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
/*
 sti r1, %:live, %1 => 0b 68 01 0007 0001

0b = 11 -> sti
68 ->description des des differents arguments => T_REG(01) + T_DIR(10) + T_DIR(10) + 0 = 68


*/
void	get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int i;
	int size;
	unsigned int code;
	i = -1;
	
	proc->cycle_to_do = op.cycle;
	proc->arcode = op.ocp ? get_instruction(vm, 1, &proc->read) : DIR_CODE << 6;
	while (++i < op.nb_arg)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3); // decomposition du arcode pour chaque code des arguments
		if (code == REG_CODE && op.args[i] & T_REG)
			size = 1;
		else if ((code == IND_CODE && op.args[i] & T_IND)
				|| (code == DIR_CODE && op.args[i] & T_DIR))
			size = (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
		op.args[i] = get_instruction(vm, size, &proc->read);
	}
}

unsigned int get_instruction(t_vm *vm, int size, unsigned int *pc)
{
	int	val;
	
	while (size--)
	{
		val = vm->mem[*pc];
		*pc = (*pc ? *pc : MEM_SIZE) - 1;
	}
	return(val);
}

void	run_corewar(t_vm *vm)
{
	t_proc *proc;
	
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle)
	{
		proc = vm->proc;
		while (proc->pnu)
		{
			if (vm->cycle == proc->cycle_to_do)
			{
				// RAPPELLE TOUTE LA MEMOIRE EST INVERSEE
			}
			else if (proc->cycle_live < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = get_instruction(vm, 1, &proc->read);
				if (proc->action <= REG_NUMBER)
					get_arg(vm, proc, op_tab[proc->action]);
			}
			proc = proc->next;
		}
		break;
		vm->cycle++;
	}
}
