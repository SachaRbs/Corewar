/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:39 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 18:10:38 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_lld(t_vm *vm, t_proc *proc)
{
	int number;

	number = (proc->arg_t[0] == DIR_CODE) ? proc->arg_v[0] :
	big_endian(vm->mem[proc->arg_a[0] + proc->arg_v[0]], 4);
	proc->reg[proc->arg_v[1]] = number;
	if (proc->reg[0])
		proc->carry = 1;
	else
		proc->carry = 0;
	return (NULL);
}