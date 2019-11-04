/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:32:01 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/29 14:56:51 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_sub(t_vm *vm, t_proc *proc)
{
	(void)vm;
	proc->reg[proc->arg_v[2]] = proc->reg[proc->arg_v[0]]
		- proc->reg[proc->arg_v[1]];
	proc->carry = proc->reg[proc->arg_v[2]] == 0 ? 1 : 0;
	return (NULL);
}
