/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:45:39 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 14:34:15 by crfernan         ###   ########.fr       */
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
	if (value > -1 * vm->pct && value < 0)
	{
		vm->last_alive = -1 * value;
		if (vm->v > 0)
			ft_printf("%s reporting in.\n", vm->contestants[-1 * value]);
	}
	return (NULL);
}
