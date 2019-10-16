/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/16 19:02:10 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

int16_t		reverser_16(int16_t a)
{
	return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}

int32_t		reverser_32(int32_t a)
{
	int32_t		tmp;

	tmp = 0;
	tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
	tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
	return (tmp);
}

int		argument(t_vm *vm, t_proc *proc, int arg)
{
	if (proc->arg_t[arg] == REG_CODE)
		return(proc->reg[proc->arg_v[arg]]);
	if (proc->arg_t[arg] == DIR_CODE)
		return(proc->arg_v[arg]);
	return(big_endian(vm->mem[proc->arg_a[arg]
		+ (proc->arg_v[arg] % IDX_MOD)], 4));
}
