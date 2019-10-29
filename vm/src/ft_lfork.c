/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:53:20 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/29 16:25:08 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

int		lfind_procnum(t_vm *vm, t_proc *proc)
{
	int			out;
	t_proc		*current;

	out = 0;
	(void)proc;
	current = vm->proc;
	while (current)
	{
		if (out <= current->procnum)
			out = current->procnum + 1;
		current = current->next;
	}
	return (out);
}

void	*ft_lfork(t_vm *vm, t_proc *proc)
{
	int			i;
	t_proc		*newproc;

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
