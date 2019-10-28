/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_live.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 19:55:09 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 21:01:28 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_live(t_vm *vm, t_proc *proc)
{
	int		value;

	value = proc->arg_v[0];
	proc->live = 1;
	vm->nbr_live++;
	if (value > 0 && value < vm->pct)
	{
		vm->last_alive = value;
		printf("%s reporting in.\n", vm->contestants[value]);
	}
	return(NULL);
}
