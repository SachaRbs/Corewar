/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lfork.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 14:53:20 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 15:29:55 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	newproc->pc = proc->arg_a[0] % MEM_SIZE;
	newproc->pnu = proc->pnu;
	newproc->procnum = find_procnum(vm);
	pushfront_proc(&vm->proc, newproc);
	return (NULL);
}
