/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:57:10 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 19:18:53 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_ldi(t_vm *vm, t_proc *proc)
{
	proc->reg[proc->arg_v[2]] = big_endian(vm->mem[(proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1) % IDX_MOD)) % MEM_SIZE], 4);
	return (NULL);
}
