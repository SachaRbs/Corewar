/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/11/06 14:58:31 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

void		last_check(t_vm *vm, t_operations *operation)
{
	if (vm->proc && vm->dump != -1 && vm->cycle == vm->dump)
		print_memory(vm->mem, vm->proc, 1);
	else
	{
		if (vm->last_alive > 0 && vm->last_alive < 5)
			ft_printf("Contestant %d, \"%s\", has won !\n",
			vm->last_alive, vm->contestants[vm->last_alive]);
		else
			ft_printf("vm->last_alive WRONG\n");
	}
	if (operation)
		free(operation);
	operation = NULL;
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
