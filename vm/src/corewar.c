/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/25 16:36:40 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

unsigned int		big_endian(unsigned int num, int n)
{
	if (n == 1)
		return (num);
	else if (n == 2)
		return (reverser_16(num));
	else if ( n == 4)
		return (reverser_32(num));
	return (-1);
}

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
	proc->arcode = op.ocp ? read_mem(vm, proc->read, 1, 1, proc) : DIR_CODE << 6;
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
			proc->arg_v[i] = read_mem(vm, proc->read, size, 1, proc);
		}
		else if (code != 0)
			return (0);
	}
	return (1);
}

void	print_memory(unsigned char *mem, t_proc *proc, int d)
{
	int i;

	i = -1;
	// ft_printf("\e[1;1H\e[2J");
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i == 0)
				printf("0x%04x : ", i);
			else
				printf("\n0x%04x : ", i);
		}
		if (i == proc->pc && d == 0)
		{
			printf("\e[36m%02hhx ", mem[i]);
			printf("\e[0m");
		}
		else if (i > proc->pc && i < (int)proc->read && d == 0)
		{
			printf("\e[32m%02hhx ", mem[i]);
			printf("\e[0m");
		}
		else
			printf("%02hhx ", mem[i]);
	}
	printf("\n");
}

void	print_action(t_proc *proc, t_vm *vm, int action_failed)
{
	unsigned int i;

	i = 0;
	if (action_failed)
	{
		if (proc->procnum < 10)
			printf("P    %d | %s", proc->procnum, g_op_tab[proc->action].name);
		else
			printf("P   %d | %s", proc->procnum, g_op_tab[proc->action].name);
		while (i < g_op_tab[proc->action].nb_arg)
		{
			if (proc->action == 11 && i != 0)
				printf(" %d", argument(vm, proc, i));		
			else if (proc->arg_t[i] == DIR_CODE)
				printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == IND_CODE)
				printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == REG_CODE)
				printf(" r%d", proc->arg_v[i]);
			i++;
		}
		if (proc->action == 11)
		{
			printf("\n       | -> store to %d + %d = %d (with pc and mod %d)",
			argument(vm, proc, 1), argument(vm, proc, 2), (argument(vm, proc, 1) + argument(vm, proc, 2)),
			proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD));
		}
		if (proc->action == 9 && proc->carry)
			printf(" OK\n");
		if (proc->action == 9 && !proc->carry)
			printf(" FAILED");
		if (proc->action == 10)
			printf("\n       | -> load from %d + %d = %d (with pc and mod %d)", argument(vm, proc, 0), argument(vm, proc, 1),
			argument(vm, proc, 0) + argument(vm, proc, 1), proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
		if (proc->action == 12)
			printf(" (%d)", proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
	}
	if (proc->action != 9 || (proc->action == 9 && !proc->carry))
	{
		if (action_failed)
			printf("\n");
		i = proc->pc;
		printf("ADV %d (0x%04x -> 0x%04x) ", proc->read - proc->pc, proc->pc, proc->read);
		while (i < proc->read)
		{
			printf("%02hhx ", vm->mem[i]);
			i++;
		}
		printf("\n");
	}
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

void	run_corewar(t_vm *vm)
{
	t_proc			*proc;
	t_operations	*operation;
	int				operation_failed;

	operation = fill_operations(vm);
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle)
	{
		printf("It is now cycle %d\n", vm->cycle);
		if (vm->cycle == 3072)
			printf("Cycle to die is now 1486\n");
		if (vm->cycle == 4558)
			printf("Cycle to die is now 1436\n");
		proc = vm->proc;
		while (proc && proc->pnu)
		{
			if (vm->cycle == proc->cycle)
			{
				if ((operation_failed = get_arg(vm, proc, g_op_tab[proc->action])))
					operation->op[proc->action - 1](vm, proc);
				print_action(proc, vm, operation_failed);
				// if (vm->dump == -1)
				// 	print_memory(vm->mem, proc, 0);
				proc->pc = proc->read;
				arg_to_zero(proc);
			}
			else if (proc->cycle < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = read_mem(vm, proc->pc, 1, 1, proc);
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
}
