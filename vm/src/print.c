/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:06:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/06 13:33:53 by sarobber         ###   ########.fr       */
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
			(i == 0) ? ft_printf("0x%04x : ", i) : ft_printf("\n0x%04x : ", i);
		if (i == proc->pc && d == 0)
			ft_printf("\e[36m%02hhx \e[0m", mem[mod_address(i)]);
		else if (i > proc->pc && i < (int)proc->read && d == 0)
			ft_printf("\e[32m%02hhx \e[0m", mem[mod_address(i)]);
		else
			ft_printf("%02hhx ", mem[mod_address(i)]);
	}
	ft_printf("\n\n\n\n");
}

void	loop_while(t_vm *vm, t_proc *proc, int i)
{
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
}

void	failed_1(t_proc *proc, t_vm *vm)
{
	if (proc->action == 15)
		ft_printf(" (%d)", proc->pc);
	if (proc->action == 12)
		ft_printf(" (%d)", proc->pc + argument(vm, proc, 0)
		+ (argument(vm, proc, 1) % IDX_MOD));
	if (proc->action == 11)
	{
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)",
		argument(vm, proc, 1), argument(vm, proc, 2),
		(argument(vm, proc, 1) + argument(vm, proc, 2)),
		proc->pc + ((argument(vm, proc, 1) + argument(vm, proc, 2)) % IDX_MOD));
	}
	if (proc->action == 10)
		ft_printf("\n       | -> load from %d + %d = %d (with pc and mod %d)",
		argument(vm, proc, 0), argument(vm, proc, 1),
		argument(vm, proc, 0) + argument(vm, proc, 1), proc->pc
		+ argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD));
	if (proc->action == 9 && proc->carry)
		ft_printf(" OK\n");
	if (proc->action == 9 && !proc->carry)
		ft_printf(" FAILED");
}

void	cut_function(t_proc *proc, t_vm *vm, int action_failed, unsigned int i)
{
	{
		if (action_failed)
			ft_printf("\n");
		i = proc->pc;
		if (i >= MEM_SIZE)
			ft_printf("ADV %d (0x%04x -> 0x%04x) ",
			proc->read - proc->pc,
			mod_address(proc->pc), mod_address(proc->read));
		else
			ft_printf("ADV %d (0x%04x -> 0x%04x) ",
			proc->read - proc->pc, proc->pc, proc->read);
		while (i < proc->read)
		{
			ft_printf("%02hhx ", vm->mem[mod_address(i)]);
			i++;
		}
		ft_printf("\n");
	}
}

void	print_action(t_proc *proc, t_vm *vm, int action_failed)
{
	unsigned int i;

	i = 0;
	if (action_failed)
	{
		if (proc->procnum > 99)
			ft_printf("P  %d | %s",
			proc->procnum, g_op_tab[proc->action].name);
		else if (proc->procnum > 9)
			ft_printf("P   %d | %s",
			proc->procnum, g_op_tab[proc->action].name);
		else
			ft_printf("P    %d | %s",
			proc->procnum, g_op_tab[proc->action].name);
		loop_while(vm, proc, i);
		failed_1(proc, vm);
	}
	if (proc->action != 9 || (proc->action == 9 && !proc->carry))
		cut_function(proc, vm, action_failed, i);
}
