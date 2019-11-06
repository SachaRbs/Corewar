/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/11/06 14:38:23 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

int			get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int				i;
	unsigned int	size;
	unsigned int	code;

	i = -1;
	proc->arcode = op.ocp ?
	read_mem_and_move_pc(vm, proc->read, 1, proc) : DIR_CODE << 6;
	vm->procct += (proc->action == 12 || proc->action == 15) ? 1 : 0;
	while (++i < MAX_ARGS_NUMBER)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3);
		if (i < op.nb_arg)
		{
			if (!(size = get_size(op, proc, code, i)))
				return (0);
			proc->arg_a[i] = proc->read;
			proc->arg_t[i] = code;
			proc->arg_v[i] = read_mem_and_move_pc(vm, proc->read, size, proc);
		}
		else if (code != 0)
			return (0);
	}
	return (1);
}

void		run_action(t_vm *vm, t_operations *operation, t_proc *proc)
{
	int		operation_failed;

	operation_failed = get_arg(vm, proc, g_op_tab[proc->action]);
	if (operation_failed)
		operation->op[proc->action - 1](vm, proc);
	if (vm->v == 2 || vm->v == 3)
		print_action(proc, vm, operation_failed);
	if (vm->p)
		print_memory(vm->mem, proc, 0);
	proc->pc = proc->read;
	arg_to_zero(proc);
}

void		get_action(t_vm *vm, t_proc *proc)
{
	proc->read = proc->pc;
	proc->action = read_mem_and_move_pc(vm, proc->pc, 1, proc);
	if (proc->action > 0 && proc->action <= NBR_OP)
		proc->cycle += g_op_tab[proc->action].cycle;
	else
	{
		proc->pc++;
		proc->cycle++;
	}
}

void		run_corewar(t_vm *vm)
{
	t_proc			*proc;
	t_operations	*operation;

	operation = fill_operations(vm);
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle
	&& (proc = vm->proc) && vm->cpt)
	{
		vm->cpt = 0;
		if (vm->v == 1 || vm->v == 3)
			ft_printf("It is now cycle %d\n", vm->cycle);
		while (proc)
		{
			if (proc->alive)
			{
				vm->cpt = 1;
				if (vm->cycle == proc->cycle)
					run_action(vm, operation, proc);
				else if (proc->cycle < vm->cycle)
					get_action(vm, proc);
			}
			proc = proc->next;
		}
		proc = --vm->next_check <= 0 ? check_live(vm) : NULL;
	}
	last_check(vm, operation);
}
