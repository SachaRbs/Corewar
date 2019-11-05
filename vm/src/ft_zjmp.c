/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:32:29 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 18:54:01 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_zjmp(t_vm *vm, t_proc *proc)
{
	int		address;

	(void)vm;
	if (proc->carry == 1)
	{
		address = proc->pc + (proc->arg_v[0] % IDX_MOD);
		proc->read = mod_address(address);
	}
	return (NULL);
}
