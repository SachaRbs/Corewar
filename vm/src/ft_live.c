/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:55:09 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/28 16:52:22 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_live(t_vm *vm, t_proc *proc)
{
	int		argument;

	proc->live = 1;
	argument = proc->arg_v[0];
	if ((argument > 0 && argument < MAX_PLAYERS) && (vm->contestants[argument] != NULL))
		vm->last_alive = argument;
	return (NULL);
}
