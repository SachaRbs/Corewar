/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 13:48:35 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_lldi(t_vm *vm, t_proc *proc)
{
	proc->reg[proc->arg_v[2]] = big_endian(vm->mem[(proc->pc + argument(vm, proc, 0) + argument(vm, proc, 1)) % MEM_SIZE], 4);
	return (NULL);	
}