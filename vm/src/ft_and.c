/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:29:12 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 13:21:02 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_and(t_vm *vm, t_proc *proc)
{
	int num[2];
	int i;

	i = -1;
	while(++i < 2)
	{
		if (proc->arg_t[i] = T_REG)
			num[i] = proc->arg_v[i];
		else if (proc->arg_t[i] = T_DIR)
			;// ??
		else if (proc->arg_t[i] = T_IND)
			num[i] = proc->pc + (proc->arg_v[i] % IDX_MOD);
	}
	proc->reg[proc->arg_v[2]] = num[0] & num[1];
}