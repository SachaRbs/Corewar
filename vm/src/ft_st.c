/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:17 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 14:16:40 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_st(t_vm *vm, t_proc *proc)
{
	if (proc->arg_t[1] == REG_CODE)
		proc->reg[proc->arg_v[1]] = proc->reg[proc->arg_v[0]];
	else if (proc->arg_t[1] == IND_CODE)
		vm->mem[(proc->pc + (proc->arg_v[1] % IDX_MOD)) % MEM_SIZE] = proc->reg[proc->arg_v[0]];
	return (NULL);
}