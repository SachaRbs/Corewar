/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:03 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 13:49:41 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_or(t_vm *vm, t_proc *proc)
{
	proc->reg[proc->arg_v[2]] = argument(vm, proc, 0) | argument(vm, proc, 1);
	proc->carry = proc->reg[proc->arg_v[2]] == 0 ? 1 : 0;
	return (NULL);
}