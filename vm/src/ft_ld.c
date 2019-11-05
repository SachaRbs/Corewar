/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:50:09 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 18:50:22 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_ld(t_vm *vm, t_proc *proc)
{
	int number;

	number = (proc->arg_t[0] == DIR_CODE) ? proc->arg_v[0] :
	read_mem(vm, proc->pc + (proc->arg_v[0] % IDX_MOD), 4);
	proc->reg[proc->arg_v[1]] = number;
	proc->carry = proc->reg[proc->arg_v[1]] ? 0 : 1;
	return (NULL);
}
