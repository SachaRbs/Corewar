/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:21 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 13:21:02 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	l_pushfront_proc_tmp(t_proc **head, t_proc *new)
{
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}

void	*ft_lfork(t_vm *vm, t_proc *proc)
{
	t_proc *newproc;
	int i;

	i = -1;
	if (newproc = ft_memalloc(sizeof(t_proc)) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	*newproc = *proc;
	l_pushfront_proc_tmp(&vm, newproc);
	newproc->pc = proc->pc + proc->arg_v[0];
	while (++i < REG_NUMBER)
		newproc->reg[i] = proc->reg[i];
	newproc->carry = proc->carry;
	newproc->cycle_live = proc->cycle_live;
	//"And something else, but more on that later."
}