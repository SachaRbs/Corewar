/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/11/06 14:40:48 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

int16_t				reverser_16(int16_t a)
{
	return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}

int32_t				reverser_32(int32_t a)
{
	int32_t		tmp;

	tmp = 0;
	tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
	tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
	return (tmp);
}

int					mod_address(int add)
{
	while (add >= MEM_SIZE)
		add -= MEM_SIZE;
	while (add < 0)
		add += MEM_SIZE;
	return (add);
}

int					argument(t_vm *vm, t_proc *proc, int arg)
{
	if (proc->arg_t[arg] == REG_CODE)
		return (proc->reg[proc->arg_v[arg]]);
	if (proc->arg_t[arg] == DIR_CODE)
		return (proc->arg_v[arg]);
	return (read_mem(vm, proc->arg_v[arg], 4));
}

void				pushfront_proc(t_proc **head, t_proc *new)
{
	new->next = NULL;
	if (head && *head && new)
	{
		new->next = *head;
		*head = new;
	}
	else
		*head = new;
}
