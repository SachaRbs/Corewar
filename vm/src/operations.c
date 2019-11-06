/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:48:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 20:48:46 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"

t_operations	*fill_operations(t_vm *vm)
{
	t_operations	*operation;

	if (!(operation = (t_operations*)ft_memalloc(sizeof(t_operations))))
		ft_exit(vm, ERROR_MALLOC);
	operation->op[0] = &ft_live;
	operation->op[1] = &ft_ld;
	operation->op[2] = &ft_st;
	operation->op[3] = &ft_add;
	operation->op[4] = &ft_sub;
	operation->op[5] = &ft_and;
	operation->op[6] = &ft_or;
	operation->op[7] = &ft_xor;
	operation->op[8] = &ft_zjmp;
	operation->op[9] = &ft_ldi;
	operation->op[10] = &ft_sti;
	operation->op[11] = &ft_fork;
	operation->op[12] = &ft_lld;
	operation->op[13] = &ft_lldi;
	operation->op[14] = &ft_lfork;
	operation->op[15] = &ft_aff;
	return (operation);
}
