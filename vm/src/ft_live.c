/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_live.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 19:55:09 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 17:35:20 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_live(t_vm *vm, t_proc *proc)
{
	t_proc	*current;

	current = vm->proc;
	proc->live = 1;
	proc->cycle_live = vm->cycle;
	while (current)
	{
		if (current->reg[1] == proc->arg_v[0])
			break;
		current = current->next;
	}
	if (current != NULL)
	{
		vm->last_alive = -current->reg[1];
		vm->nbr_live += 1;
		// proc->cycle_live = vm->cycle; //NOT SURE ABOUT THIS
		// printf("A process shows that player %d (%s) is alive\n", current->reg[1], "PLAYER NAME");
		// proc->cycle_live = 0;
	}
	return (NULL);
}

	// while (current)
	// {
	// 	if (current->pnu == proc->arg_v[0])
	// 		break;
	// 	current = current->next;
	// }
	// if (current != NULL)
	// 	vm->live = current->pnu;
