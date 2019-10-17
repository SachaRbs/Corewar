/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:17 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/17 16:50:56 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_st(t_vm *vm, t_proc *proc)
{
	vm->mem[proc->pc + (argument(vm, proc, 1) % IDX_MOD)] = proc->reg[proc->arg_v[0]];
	return (NULL);
}
