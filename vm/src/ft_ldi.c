/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:57:10 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 19:09:31 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_ldi(t_vm *vm, t_proc *proc)
{
	int address;

	address = proc->pc + ((argument(vm, proc, 0)
		+ argument(vm, proc, 1)) % IDX_MOD);
	proc->reg[proc->arg_v[2]] = read_mem(vm, address, 4);
	return (NULL);
}
