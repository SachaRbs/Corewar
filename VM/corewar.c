/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:39:50 by sarobber          #+#    #+#             */
/*   Updated: 2019/09/11 12:05:22 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	run_corewar(t_vm *vm)
{
	t_proc *proc;
	
	while (proc = vm->proc && (vm->dump == -1 || vm->cycle < vm->dump))
	{
		while (proc)
		{
			
			proc = proc->next;
		}	
		vm->cycle++;
	}
}