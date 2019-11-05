/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:01:36 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 18:52:40 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

void	writing_mem(t_vm *vm, int pc, int bytes, int value)
{
	int i;
	int sign;
	int end;
	int div;
	int hex;
	int address;

	sign = 1;
	bytes *= 2;
	if (pc < 0)
		pc = MEM_SIZE + pc;
	if (value < 0)
	{
		sign = -1;
		value *= -1;
	}
	i = 0;
	while(i < bytes)
	{
		div = ft_power(16, (bytes - 1 - i));
		hex = 16 * (value / div);
		i++;
		value %= div;
		div = ft_power(16, (bytes - 1 - i));
		hex += (value / div);
		i++;
		address = mod_address(pc + (i - 1) / 2);
		if (sign == 1)
			vm->mem[address] = hex;
		else if ((end = value % div))
			vm->mem[address] = 255 - hex;
		else
			vm->mem[address] = 256 - hex;
		value %= div;
	}
}
