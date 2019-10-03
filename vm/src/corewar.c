/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/03 15:20:52 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
 sti r1, %:live, %1 => 0b 68 01 0007 0001

0b = 11 -> sti
68 ->description des des differents arguments => T_REG(01) + T_DIR(10) + T_DIR(10) + 0 = 68


*/

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

void	get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int i;
	int size;
	unsigned int code;
	i = -1;
	
	proc->cycle += op.cycle;
	proc->arcode = op.ocp ? get_instruction(vm, 1, &proc->read) : DIR_CODE << 6;
	while (++i < op.nb_arg)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3); // decomposition du arcode pour chaque code des arguments
		if (code == REG_CODE && op.args[i] & T_REG)
			size = 1;
		else if ((code == IND_CODE && op.args[i] & T_IND)
				|| (code == DIR_CODE && op.args[i] & T_DIR))
			size = (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
		// proc->arg[i] = get_instruction(vm, size, &proc->read);
	}
}

void	print_action(t_proc *proc)
{
	int i = 0;
	printf("PLAYER No %d :\n", proc->pnu);
	printf("action = %s\n", op_tab[proc->action].name);
	while (++i < op_tab[proc->action].nb_arg) {
		// printf("arg[%d] = %s\n", i, proc->arg[i]);
	}
	printf("\n\n");
}

void	run_corewar(t_vm *vm)
{
	t_proc *proc;
	
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle)
	{
		proc = vm->proc;
		while (proc->pnu)
		{
			if (vm->cycle == proc->cycle)
			{
				print_action(proc);
				proc->pc = proc->read;
			}
			else if (proc->cycle < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = get_instruction(vm, 1, &proc->read);
				if (proc->action <= NBR_OP)
					get_arg(vm, proc, op_tab[proc->action]);
			}
			proc = proc->next;
		}
		vm->cycle++;
	}
}