/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:55:09 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/22 13:05:00 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_live(t_vm *vm, t_proc *proc)
{
	t_proc	*current;

	current = vm->proc;
	while (current)
	{
		if (current->reg[1] == proc->arg_v[0])
			break;
		current = current->next;
	}
	if (current != NULL)
	{
		vm->live = current->reg[1];
		// proc->cycle_live = vm->cycle; //NOT SURE ABOUT THIS
		printf("A process shows that player %d (%s) is alive\n", current->reg[1], "PLAYER NAME");
		proc->cycle_live = 0;
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
