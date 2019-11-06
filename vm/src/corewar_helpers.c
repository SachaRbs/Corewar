/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:33:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/06 14:40:07 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

int			wrong_ocp(t_proc *proc, t_op op)
{
	int code;
	int i;

	i = -1;
	proc->read = proc->pc + 2;
	while (++i < op.nb_arg)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3);
		if (code == REG_CODE)
			proc->read += REG_SIZE;
		else if (code == IND_CODE || code == DIR_CODE)
			proc->read += (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
	}
	return (0);
}

int			get_size(t_op op, t_proc *proc, int code, int i)
{
	int size;

	size = 0;
	if (code == REG_CODE && op.args[i] & T_REG)
		size = 1;
	else if ((code == IND_CODE && op.args[i] & T_IND)
			|| (code == DIR_CODE && op.args[i] & T_DIR))
		size = (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
	else
	{
		proc->read -= size;
		return (wrong_ocp(proc, op));
	}
	return (size);
}

void		arg_to_zero(t_proc *proc)
{
	size_t	i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		proc->arg_a[i] = 0;
		proc->arg_v[i] = 0;
		proc->arg_t[i] = 0;
		i++;
	}
}

void		*check_live(t_vm *vm)
{
	t_proc *proc;
	t_proc *tmp;

	tmp = NULL;
	proc = vm->proc;
	if ((vm->nbr_live > NBR_LIVE || ++vm->check > MAX_CHECKS)
			&& (vm->check = 1))
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->v == 1 || vm->v == 3)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
	}
	while (proc)
	{
		if (!proc->live)
			proc->alive = 0;
		else
			proc->live = 0;
		proc = proc->next;
	}
	vm->nbr_live = 1;
	vm->next_check = vm->cycle_to_die;
	return (NULL);
}

void		last_check(t_vm *vm, t_operations *operation)
{
	if (vm->proc && vm->dump != -1 && vm->cycle == vm->dump)
		print_memory(vm->mem, vm->proc, 1);
	else
	{
		if (vm->last_alive > 0 && vm->last_alive < 5)
			ft_printf("Cylce = %d\nContestant %d, \"%s\", has won !\n",
			vm->cycle, vm->last_alive, vm->contestants[vm->last_alive]);
		else
			ft_printf("vm->last_alive WRONG\n");
	}
	if (operation)
		free(operation);
	operation = NULL;
}
