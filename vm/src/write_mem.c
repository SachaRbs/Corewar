/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:01:36 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/06 14:06:03 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

void	write_negative(t_vm *vm, int pc, int bytes, int value)
{
	int div;
	int hex;
	int	i;

	i = 0;
	while (i < bytes)
	{
		div = ft_power(16, (bytes - 1 - i));
		hex = 16 * (value / div);
		i++;
		value %= div;
		div = ft_power(16, (bytes - 1 - i));
		hex += (value / div);
		i++;
		if (div != 1)
			vm->mem[mod_address(pc + (i - 1) / 2)] = 255 - hex;
		else
			vm->mem[mod_address(pc + (i - 1) / 2)] = 256 - hex;
		value %= div;
	}
}

void	write_positive(t_vm *vm, int pc, int bytes, int value)
{
	int div;
	int hex;
	int	i;

	i = 0;
	while (i < bytes)
	{
		div = ft_power(16, (bytes - 1 - i));
		hex = 16 * (value / div);
		i++;
		value %= div;
		div = ft_power(16, (bytes - 1 - i));
		hex += (value / div);
		i++;
		vm->mem[mod_address(pc + (i - 1) / 2)] = hex;
		value %= div;
	}
}

void	writing_mem(t_vm *vm, int pc, int bytes, int value)
{
	pc = mod_address(pc);
	if (value < 0)
		write_negative(vm, pc, bytes * 2, value * -1);
	else
		write_positive(vm, pc, bytes * 2, value);
}
