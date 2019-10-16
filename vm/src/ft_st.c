/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:17 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 13:21:02 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_st(t_vm *vm, t_proc *proc)
{
	if (((proc->arcode >> 4) & 0b11) == IND_CODE)
		vm->mem[proc->pc + proc->arg_v[1] % IDX_MOD] = proc->arg_v[0];  // TRONQUEZ PAR ID_MODE
	else
		proc->reg[proc->arg_v[1]] = proc->arg_v[0];

}