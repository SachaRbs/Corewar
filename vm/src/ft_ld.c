/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:57:10 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 17:40:23 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_ld(t_vm *vm, t_proc *proc)
{
	int number;

	number = (proc->arg_t[0] == DIR_CODE) ? proc->arg_v[0] :
	big_endian(vm->mem[(proc->pc + (proc->arg_v[0] % IDX_MOD)) % MEM_SIZE], 4);
	proc->reg[proc->arg_v[1]] = number;
	proc->carry = proc->reg[proc->arg_v[1]] ? 0 : 1;
	return (NULL);
}

