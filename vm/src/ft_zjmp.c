/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:32:29 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 20:12:25 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_zjmp(t_vm *vm, t_proc *proc)
{
	(void)vm;
	if (proc->carry == 1)
		proc->pc = proc->arg_a[0] + (proc->arg_v[0] % IDX_MOD);
	return (NULL);
}
