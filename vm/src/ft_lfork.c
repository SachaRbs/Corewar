/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:21 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/22 12:18:32 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

int		lfind_procnum(t_vm *vm, t_proc *proc)
{
	t_proc		*current;
	int 		out;

	out = 0;
	current = vm->proc;
	while(current)
	{
		if (current->pnu == proc->pnu
			&& out < current->procnum)
			out = proc->procnum;
		current = current->next;
	}
	out++;
	return (out);
}

void	*ft_lfork(t_vm *vm, t_proc *proc)
{
	t_proc *newproc;
	int i;

	i = -1;
	if ((newproc = (t_proc*)ft_memalloc(sizeof(t_proc))) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	while (++i < REG_NUMBER)
		newproc->reg[i] = proc->reg[i];
	newproc->carry = proc->carry;
	newproc->cycle_live = proc->cycle_live;
	newproc->pc = proc->arg_a[0] % MEM_SIZE;
	newproc->pnu = proc->pnu;
	newproc->procnum = lfind_procnum(vm, proc);
	pushfront_proc(&vm->proc, newproc);
	return (NULL);
}
