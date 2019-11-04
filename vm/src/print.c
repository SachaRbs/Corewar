/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:06:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/31 15:29:15 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

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
			printf("\e[36m%02hhx ", mem[mod_address(i)]);
			printf("\e[0m");
		}
		else if (i > proc->pc && i < (int)proc->read && d == 0)
		{
			printf("\e[32m%02hhx ", mem[mod_address(i)]);
			printf("\e[0m");
		}
		else
			printf("%02hhx ", mem[mod_address(i)]);
	}
	printf("\n");
}


void	print_action(t_proc *proc, t_vm *vm, int action_failed)
{
	unsigned int i;

	i = 0;
	if (action_failed)
	{
		if (proc->procnum > 99)
			printf("P  %d | %s", proc->procnum, g_op_tab[proc->action].name);
		else if (proc->procnum > 9)
			printf("P   %d | %s", proc->procnum, g_op_tab[proc->action].name);
		else
			printf("P    %d | %s", proc->procnum, g_op_tab[proc->action].name);
		while (i < g_op_tab[proc->action].nb_arg)
		{
			if (proc->action == 11 && i != 0)
				printf(" %d", argument(vm, proc, i));
			else if (proc->action == 10 && i == 0)
				printf(" %d", argument(vm, proc, i));
			else if (proc->action == 8 && i == 0)
				printf(" %d", argument(vm, proc, i));
			else if (proc->action == 6 && i == 0)
				printf(" -%d", proc->arg_v[i]);
			else if (proc->action == 3 && i != 0)
				printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == DIR_CODE)
				printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == IND_CODE)
				printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == REG_CODE)
				printf(" r%d", proc->arg_v[i]);
			i++;
		}		
		if (proc->action == 15)
			printf(" (%d)", proc->pc);
		if (proc->action == 12)
			printf(" (%d)", proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
		// if (proc->action == 11 && (vm->cycle == 8470 || vm->cycle == 8650 || vm->cycle == 8708))
		// {
		// 	printf("\n       | -> store to %d + %d = %d (with pc and mod -%d)",
		// 	argument(vm, proc, 1), argument(vm, proc, 2), (argument(vm, proc, 1) + argument(vm, proc, 2)),
		// 	MEM_SIZE - (proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD)));
		// }
		if (proc->action == 11)
		{
			printf("\n       | -> store to %d + %d = %d (with pc and mod %d)",
			argument(vm, proc, 1), argument(vm, proc, 2), (argument(vm, proc, 1) + argument(vm, proc, 2)),
			proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD));
		}
		if (proc->action == 10)
			printf("\n       | -> load from %d + %d = %d (with pc and mod %d)", argument(vm, proc, 0), argument(vm, proc, 1),
			argument(vm, proc, 0) + argument(vm, proc, 1), proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
		if (proc->action == 9 && proc->carry)
			printf(" OK\n");
		if (proc->action == 9 && !proc->carry)
			printf(" FAILED");
	}
	if (proc->action != 9 || (proc->action == 9 && !proc->carry))
	{
		if (action_failed)
			printf("\n");
		i = proc->pc;
		if (i >= MEM_SIZE)
			printf("ADV %d (0x%04x -> 0x%04x) ", proc->read - proc->pc, mod_address(proc->pc), mod_address(proc->read));
		else
			printf("ADV %d (0x%04x -> 0x%04x) ", proc->read - proc->pc, proc->pc, proc->read);
		while (i < proc->read)
		{
			printf("%02hhx ", vm->mem[mod_address(i)]);
			i++;
		}
		// printf("P    %d | %s", proc->procnum, g_op_tab[proc->action].name);
		printf("\n");
	}
}
