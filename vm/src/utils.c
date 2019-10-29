/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/29 20:00:10 by sarobber         ###   ########.fr       */
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

unsigned int		big_endian(unsigned int num, int n)
{
	if (n == 1)
		return (num);
	else if (n == 2)
		return (reverser_16(num));
	else if (n == 4)
		return (reverser_32(num));
	return (-1);
}

void	writing_mem(t_vm *vm, int pc, int bytes, int value)
{
	int i;
	int sign;
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
		address = pc + (i - 1) / 2;
		// if (sign == 1)
		// 	vm->mem[mod_address(address)] = hex;
		// else if (div > 1)
		// 	vm->mem[mod_address(address)] = 255 - hex;
		// else
		// 	vm->mem[mod_address(address)] = 256 - hex;
		if (address >= MEM_SIZE)
			address = MEM_SIZE - address;
		if (address < 0)
			address = MEM_SIZE + address;
		if (sign == 1)
			vm->mem[address] = hex;
		else if (div > 1)
			vm->mem[address] = 255 - hex;
		else
			vm->mem[address] = 256 - hex;
		value %= div;
	}
}


int		mod_address(int add)
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
	return (big_endian(vm->mem[(proc->pc
		+ (proc->arg_v[arg] % IDX_MOD)) % MEM_SIZE], 4));
}
