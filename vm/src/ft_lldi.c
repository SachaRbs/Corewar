/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/29 15:34:39 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

/*
***		WRONG ?
*/

void	*ft_lldi(t_vm *vm, t_proc *proc)
{
	int address;

	address = (proc->pc + argument(vm, proc, 0) + (argument(vm, proc, 1)));
	proc->reg[proc->arg_v[2]] = read_mem(vm, address, 4);
	return (NULL);
}
