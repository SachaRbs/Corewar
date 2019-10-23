/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/23 18:39:11 by sarobber         ###   ########.fr       */
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

unsigned int	get_instruction(t_vm *vm, int size, unsigned int *pc)
{
	int		val;

	val = 0;
	if (*pc + size < MEM_SIZE)
		ft_memcpy(&val, &(vm->mem[*pc % MEM_SIZE]), size);
	else
		val = -1;
	*pc += size;
	return (big_endian(val, size));
}

int		get_arg(t_vm *vm, t_proc *proc, t_op op)
{
	int				i;
	unsigned int	size;
	unsigned int	code;

	i = -1;
	// proc->cycle += op.cycle;
	proc->arcode = op.ocp ? get_instruction(vm, 1, &proc->read) : DIR_CODE << 6;
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
				return (0);
			proc->arg_a[i] = proc->read;
			proc->arg_t[i] = code;
			proc->arg_v[i] = get_instruction(vm, size, &proc->read);
		}
		else if (code != 0)
			return (0);
	}
		return (1);
}

void	print_action(t_proc *proc)
{
	int	i;

	i = 0;
	printf("PLAYER No %d :\n", proc->pnu);
	printf("action = %s\n", g_op_tab[proc->action].name);
	while (i < 4){
		printf("arg_v[%d] = %d\n",i, proc->arg_v[i]);
		proc->arg_v[i] = 0;
		i++;
	}
	printf("\n\n");
}

void	print_memory2(unsigned char *mem, t_proc *proc, int d)
{
	int i;

	i = -1;
	// sleep(1);
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

void	print_action2(t_proc *proc, t_vm *vm)
{
	int i;

	i = -1;
	printf("Proc = %d || Action = %s || PC = %d {0x%04x} || Read = %d {0x%04x} || Arg[] = ", proc->procnum, g_op_tab[proc->action].name, proc->pc, proc->pc, proc->read, proc->read);
	while (++i < g_op_tab[proc->action].nb_arg)
		printf("%d ", proc->arg_v[i]);
	if (proc->action == 11)
		printf("\n\t-> addres = %d || reg[%d] = %d", (proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD)) % MEM_SIZE, 15, proc->reg[15]);
	if (proc->action == 10)
	{
		printf("\n\t-> address = %d, reg[%d] = %d || arg0 = %d || arg1 = %d",
		(proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD)) % MEM_SIZE, 15, proc->reg[15], proc->arg_v[0], proc->arg_v[1]);
	}
	if (proc->action == 9)
	{
		if (proc->carry == 0)
			printf("FAIL");
	}

	printf("\n");
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
	t_proc	*proc;
	t_operations	*operation;

	operation = fill_operations(vm);
	while ((vm->dump == -1 || vm->cycle < vm->dump) && ++vm->cycle)
	{
		printf("It is now cycle %d\n", vm->cycle);
		proc = vm->proc;
		while (proc && proc->pnu)
		{
			if (vm->cycle == proc->cycle)
			{
				get_arg(vm, proc, g_op_tab[proc->action]);
				operation->op[proc->action - 1](vm, proc);
				print_action2(proc, vm);
				if (vm->dump == -1)
				{
					print_memory2(vm->mem, proc, 0);
					// getchar();
				}
				proc->pc = proc->read;
				arg_to_zero(proc);
			}
			else if (proc->cycle < vm->cycle)
			{
				proc->read = proc->pc;
				proc->action = get_instruction(vm, 1, &proc->read);
				if (proc->action > 0 && proc->action <= NBR_OP)
					proc->cycle += g_op_tab[proc->action].cycle;
				else
					proc->pc++;
			}
			proc = proc->next;
		}
	}
	if (vm->cycle == vm->dump)
		print_memory2(vm->mem, vm->proc, 1);
}
