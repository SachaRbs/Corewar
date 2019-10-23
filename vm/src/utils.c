/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/23 15:34:53 by sarobber         ###   ########.fr       */
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
	return(big_endian(vm->mem[(proc->pc + (proc->arg_v[arg] % IDX_MOD)) % MEM_SIZE], 4));
}

void	writing_mem(t_vm *vm, int pc, int bytes, int value)
{
	int i;
	int sign;
	int div;
	int hex;

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
		if (sign == 1)
			vm->mem[pc + (i - 1) / 2] = hex;
		else if (div > 1)
			vm->mem[pc + (i - 1) / 2] = 255 - hex;
		else
			vm->mem[pc + (i - 1) / 2] = 256 - hex;
		value %= div;
	}
}

int	read_mem(t_vm *vm, int address, int bytes)
{
	int value;
	int multi;
	int temp1;
	int temp2;
	int i;
	int j;
	int neg;

	i = 0;
	j = 0;
	value = 0;
	bytes *= 2;
	neg = vm->mem[address] > 239 ? -1 : 1;
	while (i < bytes)
	{
		temp1 = neg == -1 ? 15 - (vm->mem[address + j] / 16) : (vm->mem[address + j]) / 16;
		temp2 = neg == -1 ? 15 - (vm->mem[address + j] % 16) : vm->mem[address + j] % 16;
		multi = temp1 * ft_power(16, (bytes) - 1 - i);
		value += multi;
		i++;
		multi = temp2 * ft_power(16, (bytes) - 1 - i);
		value += multi;
		i++;
		j++;
	}
	value += neg == -1 ? 1 : 0;
	return(neg * value);
}