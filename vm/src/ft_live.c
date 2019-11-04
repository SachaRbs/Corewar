/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:45:39 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/04 19:37:00 by crfernan         ###   ########.fr       */
/*                                                                            */
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
		if (vm->v > 0)
			ft_printf("%s reporting in.\n", vm->contestants[value]);
	}
	return (NULL);
}
