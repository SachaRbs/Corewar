/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:29:12 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 13:32:55 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_and(t_vm *vm, t_proc *proc)
{
	proc->reg[proc->arg_v[2]] = argument(vm, proc, 0) & argument(vm, proc, 1);
	proc->carry = proc->reg[proc->arg_v[2]] == 0 ? 1 : 0;
	return (NULL);
}
