/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/29 17:07:38 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

int		wrong_ocp(t_proc *proc, t_op op)
{
	int code;
	int i;

	i = -1;
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

int		get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int				i;
	unsigned int	size;
	unsigned int	code;

	i = -1;
	proc->arcode = op.ocp ? read_mem_and_move_pc(vm, proc->read, 1, proc) : DIR_CODE << 6;
	while (++i < MAX_ARGS_NUMBER)
	{
		code = ((proc->arcode >> (6 - i * 2)) & 3);
		if (i < op.nb_arg)
		{
			if (code == REG_CODE && op.args[i] & T_REG)
				size = 1;
			else if ((code == IND_CODE && op.args[i] & T_IND) || (code == DIR_CODE && op.args[i] & T_DIR))
				size = (code == IND_CODE || op.index) ? IND_SIZE : DIR_SIZE;
			else
				return (wrong_ocp(proc, op));
			proc->arg_a[i] = proc->read;
			proc->arg_t[i] = code;
			proc->arg_v[i] = read_mem_and_move_pc(vm, proc->read, size, proc);
		}
		else if (code != 0)
			return (0);
	}
	return (1);
}

void	arg_to_zero(t_proc *proc)
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

t_proc		*check_live(t_vm *vm)
{
	t_proc *proc;
	t_proc *tmp;


	tmp = NULL;
	proc = vm->proc;
	if ((vm->nbr_live > NBR_LIVE || ++vm->check > MAX_CHECKS) && (vm->check = 1))
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		printf("Cycle to die is now %d\n", vm->cycle_to_die);
	}
	while (proc)
	{
		if (!proc->live)
		{
			if (tmp)
				tmp->next = proc->next;
			else
				vm->proc = vm->proc->next;
			free(proc);
			proc = tmp ? tmp->next : vm->proc;
		}
		else if ((tmp = proc))
		{
			proc->live = 0;
			proc = proc->next;
		}
	}
	vm->nbr_live = 1;
	vm->next_check = vm->cycle_to_die;
	return(vm->proc);
}

void	run_corewar(t_vm *vm)
{
	t_proc			*proc;
	t_operations	*operation;
	int				operation_failed;

	operation = fill_operations(vm);
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle
	&& printf("It is now cycle %d\n", vm->cycle)
	&& (proc = --vm->next_check <= 0 ? check_live(vm) : vm->proc))
	{
		while (proc && proc->pnu)
		{
			if (vm->cycle == proc->cycle)
			{
				if ((operation_failed = get_arg(vm, proc, g_op_tab[proc->action])))
					operation->op[proc->action - 1](vm, proc);
				print_action(proc, vm, operation_failed);
				// if (vm->dump == -1)
					// print_memory(vm->mem, proc, 0);
				proc->pc = proc->read;
				arg_to_zero(proc);
			}
			else if (proc->cycle < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = read_mem_and_move_pc(vm, proc->pc, 1, proc);
				if (proc->action > 0 && proc->action <= NBR_OP)
					proc->cycle += g_op_tab[proc->action].cycle;
				else
				{
					proc->pc++;
					proc->cycle++; //THIS IS SOMETHING THAT CRISTINA DECIDED TO INVENT
				}
			}
			proc = proc->next;
		}
	}
	if (vm->cycle == vm->dump)
		print_memory(vm->mem, vm->proc, 1);
	else
		if (vm->last_alive > 0 && vm->last_alive < 5)
			printf("Contestant %d, \"%s\", has won !\n", vm->last_alive, vm->contestants[vm->last_alive]);
		else
			printf("vm->last_alive WRONG\n");
}
