/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/15 20:28:06 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"

unsigned int	get_instruction(t_vm *vm, int size, unsigned int *pc)
{
	int		val;

	val = 0;
	if (*pc + size < MEM_SIZE)
		ft_memcpy(&val, &(vm->mem[*pc]), size);
	else
		val = -1;
	*pc += size;
	return (big_endian(val, size));
}

void			get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int				i;
	unsigned int	size;
	unsigned int	code;

	i = -1;
	proc->cycle += op.cycle;
	proc->arcode = op.ocp ? get_instruction(vm, 1, &proc->read) : DIR_CODE << 6;
	while (++i < op.nb_arg)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3);
		if (code == REG_CODE && op.args[i] & T_REG)
			size = 1;
		else if ((code == IND_CODE && op.args[i] & T_IND)
		|| (code == DIR_CODE && op.args[i] & T_DIR))
			size = (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
		proc->arg[i] = get_instruction(vm, size, &proc->read);
	}
}

void			print_action(t_proc *proc)
{
	int	i;

	i = 0;
	printf("PLAYER No %d :\n", proc->pnu);
	printf("action = %s\n", op_tab[proc->action].name);
	while (i < 4)
	{
		printf("arg[%d] = %d\n", i, proc->arg[i]);
		proc->arg[i] = 0;
		i++;
	}
	printf("\n\n");
}

void			run_corewar(t_vm *vm)
{
	t_proc			*proc;
	t_operations	*operation;

	operation = fill_operations(vm);
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle)
	{
		proc = vm->proc;
		while (proc && proc->pnu)
		{
			if (vm->cycle == proc->cycle)
			{
				operation->op[proc->action - 1](vm, proc);
				// print_action(proc);
				proc->pc = proc->read;
				getchar();
			}
			else if (proc->cycle < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = get_instruction(vm, 1, &proc->read);
				if (proc->action > 0 && proc->action <= NBR_OP)
					get_arg(vm, proc, op_tab[proc->action]);
			}
			proc = proc->next;
		}
	}
}
// when we move the pc higher than MEMN_MAX just put it to 0
