/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:06:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 20:44:06 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "operations.h"
#include "op.h"

void	print_memory(unsigned char *mem, t_proc *proc, int d)
{
	int i;

	i = -1;
	sleep(1);
	while (proc && mem && ++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i == 0)
				ft_printf("0x%04x : ", i);
			else
				ft_printf("\n0x%04x : ", i);
		}
		if (i == proc->pc && d == 0)
		{
			ft_printf("\e[36m%02hhx ", mem[mod_address(i)]);
			ft_printf("\e[0m");
		}
		else if (i > proc->pc && i < (int)proc->read && d == 0)
		{
			ft_printf("\e[32m%02hhx ", mem[mod_address(i)]);
			ft_printf("\e[0m");
		}
		else
			ft_printf("%02hhx ", mem[mod_address(i)]);
	}
	ft_printf("\n\n\n\n");
}


void	print_action(t_proc *proc, t_vm *vm, int action_failed)
{
	unsigned int i;

	i = 0;
	if (action_failed)
	{
		if (proc->procnum > 99)
			ft_printf("P  %d | %s", proc->procnum, g_op_tab[proc->action].name);
		else if (proc->procnum > 9)
			ft_printf("P   %d | %s", proc->procnum, g_op_tab[proc->action].name);
		else
			ft_printf("P    %d | %s", proc->procnum, g_op_tab[proc->action].name);
		while (i < g_op_tab[proc->action].nb_arg)
		{
			if (proc->action == 11 && i != 0)
				ft_printf(" %d", argument(vm, proc, i));
			else if (proc->action == 10 && i == 0)
				ft_printf(" %d", argument(vm, proc, i));
			else if (proc->action == 8 && i == 0)
				ft_printf(" %d", argument(vm, proc, i));
			else if (proc->action == 6 && i == 0)
				ft_printf(" -%d", proc->arg_v[i]);
			else if (proc->action == 3 && i != 0)
				ft_printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == DIR_CODE)
				ft_printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == IND_CODE)
				ft_printf(" %d", proc->arg_v[i]);
			else if (proc->arg_t[i] == REG_CODE)
				ft_printf(" r%d", proc->arg_v[i]);
			i++;
		}		
		if (proc->action == 15)
			ft_printf(" (%d)", proc->pc);
		if (proc->action == 12)
			ft_printf(" (%d)", proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
		// if (proc->action == 11 && (vm->cycle == 8470 || vm->cycle == 8650 || vm->cycle == 8708))
		// {
		// 	ft_printf("\n       | -> store to %d + %d = %d (with pc and mod -%d)",
		// 	argument(vm, proc, 1), argument(vm, proc, 2), (argument(vm, proc, 1) + argument(vm, proc, 2)),
		// 	MEM_SIZE - (proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD)));
		// }
		if (proc->action == 11)
		{
			ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)",
			argument(vm, proc, 1), argument(vm, proc, 2), (argument(vm, proc, 1) + argument(vm, proc, 2)),
			proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD));
		}
		if (proc->action == 10)
			ft_printf("\n       | -> load from %d + %d = %d (with pc and mod %d)", argument(vm, proc, 0), argument(vm, proc, 1),
			argument(vm, proc, 0) + argument(vm, proc, 1), proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
		if (proc->action == 9 && proc->carry)
			ft_printf(" OK\n");
		if (proc->action == 9 && !proc->carry)
			ft_printf(" FAILED");
	}
	if (proc->action != 9 || (proc->action == 9 && !proc->carry))
	{
		if (action_failed)
			ft_printf("\n");
		i = proc->pc;
		if (i >= MEM_SIZE)
			ft_printf("ADV %d (0x%04x -> 0x%04x) ", proc->read - proc->pc, mod_address(proc->pc), mod_address(proc->read));
		else
			ft_printf("ADV %d (0x%04x -> 0x%04x) ", proc->read - proc->pc, proc->pc, proc->read);
		while (i < proc->read)
		{
			ft_printf("%02hhx ", vm->mem[mod_address(i)]);
			i++;
		}
		// printf("P    %d | %s", proc->procnum, g_op_tab[proc->action].name);
		ft_printf("\n");
	}
}
