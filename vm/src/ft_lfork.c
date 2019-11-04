/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:53:20 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/31 16:52:52 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

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
	newproc->cycle = vm->cycle;
	newproc->pnu = proc->pnu;
	newproc->pc = mod_address(proc->pc + proc->arg_v[0]);
	newproc->procnum = vm->procct;
	pushfront_proc(&vm->proc, newproc);
	return (NULL);
}
