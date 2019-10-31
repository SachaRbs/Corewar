/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:47:53 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/31 16:52:45 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_fork(t_vm *vm, t_proc *proc)
{
	int			i;
	t_proc		*newproc;

	i = -1;
	if ((newproc = (t_proc*)ft_memalloc(sizeof(t_proc))) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	while (++i < REG_NUMBER)
		newproc->reg[i] = proc->reg[i];
	newproc->carry = proc->carry;
	newproc->cycle = vm->cycle;
	newproc->cycle_live = proc->cycle_live;
	newproc->pc = mod_address(proc->pc + (proc->arg_v[0] % IDX_MOD));
	newproc->pnu = proc->pnu;
	newproc->procnum = vm->procct;
	pushfront_proc(&vm->proc, newproc);
	return (NULL);
}
