/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:29:12 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 18:44:47 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

int		argument(t_vm *vm, t_proc *proc, int arg)
{
	if (proc->arg_t[arg] == REG_CODE)
		return(proc->reg[proc->arg_v[arg]]);
	if (proc->arg_t[arg] == DIR_CODE)
		return(proc->arg_v[arg]);
	return(big_endian(vm->mem[proc->arg_a[arg]
		+ (proc->arg_v[arg] % IDX_MOD)], 4));
}

void	*ft_and(t_vm *vm, t_proc *proc)
{
	proc->reg[proc->arg_v[2]] = argument(vm, proc, 0) & argument(vm, proc, 1);
	return (NULL);
}

// void	*ft_and(t_vm *vm, t_proc *proc)
// {
// 	int num[2];
// 	int i;

// 	i = -1;
// 	while(++i < 2)
// 	{
// 		if (proc->arg_t[i] = T_REG)
// 			num[i] = proc->arg_v[i];
// 		else if (proc->arg_t[i] = T_DIR)
// 			;// ??
// 		else if (proc->arg_t[i] = T_IND)
// 			num[i] = proc->pc + (proc->arg_v[i] % IDX_MOD);
// 	}
// 	proc->reg[proc->arg_v[2]] = num[0] & num[1];
// }