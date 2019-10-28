/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lfork.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 20:30:21 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 21:50:39 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "operations.h"
#include "error.h"
#include "op.h"

int		lfind_procnum(t_vm *vm, t_proc *proc)
{
	t_proc		*current;
	int 		out;

	out = 0;
	(void)proc;
	current = vm->proc;
	while(current)
	{
		if (out <= current->procnum)
			out = current->procnum + 1;
		current = current->next;
	}
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
