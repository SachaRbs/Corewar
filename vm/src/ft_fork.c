/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:29:25 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/17 15:34:03 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_fork(t_vm *vm, t_proc *proc)
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
	newproc->pc = proc->arg_a[0] % IDX_MOD;
	newproc->pnu = proc->pnu;
	pushfront_proc(&vm->proc, newproc);
	// pushfront_proc(&vm->first_proc, newproc);
	return (NULL);
}
