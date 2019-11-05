/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:17 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 18:55:18 by crfernan         ###   ########.fr       */
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
		writing_mem(vm, proc->pc + (proc->arg_v[1] % IDX_MOD), 4,
			proc->reg[proc->arg_v[0]]);
	return (NULL);
}
