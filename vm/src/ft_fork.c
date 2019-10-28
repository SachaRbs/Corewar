/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 20:29:25 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 21:49:37 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "operations.h"
#include "error.h"
#include "op.h"

int		find_procnum(t_vm *vm, t_proc *proc)
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
	newproc->cycle = vm->cycle;
	newproc->cycle_live = proc->cycle_live;
	newproc->pc = (proc->pc + (proc->arg_v[0] % IDX_MOD)) % MEM_SIZE;
	// if (newproc->pc)
	// 	newproc->pc = MEM_SIZE - newproc->pc;
	newproc->pnu = proc->pnu;
	newproc->procnum = find_procnum(vm, proc);
	pushfront_proc(&vm->proc, newproc);
	// pushfront_proc(&vm->first_proc, newproc);
	return (NULL);
}
