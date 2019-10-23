/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:32:29 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/23 17:51:45 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_zjmp(t_vm *vm, t_proc *proc)
{
	int		address;

	address = 0;
	(void)vm;
	if (proc->carry == 1)
	{
		address = (proc->pc + (proc->arg_v[0] % IDX_MOD)) % MEM_SIZE;
		if (address < 0)
			proc->read = MEM_SIZE + address;
		else
			proc->read = address;
	}
	return (NULL);
}
