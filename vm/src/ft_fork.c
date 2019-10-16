/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:29:25 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 18:58:05 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	pushfront_proc_tmp(t_proc **head, t_proc *new)
{
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void	*ft_fork(t_vm *vm, t_proc *proc)
{
	t_proc *newproc;
	int i;

	i = -1;
	if ((newproc = (t_proc*)ft_memalloc(sizeof(t_proc))) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	*newproc = *proc;
	pushfront_proc_tmp(&vm->proc, newproc);
	newproc->pc = proc->arg_a[0] % IDX_MOD;
	while (++i < REG_NUMBER)
		newproc->reg[i] = proc->reg[i];
	newproc->carry = proc->carry;
	newproc->cycle_live = proc->cycle_live;
	//"And something else, but more on that later."
	return (NULL);
}
