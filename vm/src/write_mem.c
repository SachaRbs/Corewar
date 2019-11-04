/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_mem.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sacha <sacha@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 17:01:36 by crfernan     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/03 18:35:24 by sacha       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
		// address = pc + (i - 1) / 2;
		address = mod_address(pc + (i - 1) / 2);
		// if (sign == 1)
		// 	vm->mem[mod_address(address)] = hex;
		// else if (div > 1)
		// 	vm->mem[mod_address(address)] = 255 - hex;
		// else
		// 	vm->mem[mod_address(address)] = 256 - hex;
		// if (address >= MEM_SIZE)
		// 	address = address - MEM_SIZE;
		// if (address < 0)
		// 	address = MEM_SIZE + address;
		if (sign == 1)
			vm->mem[address] = hex;
		else if ((end = value % div))
			vm->mem[address] = 255 - hex;
		else
			vm->mem[address] = 256 - hex;
		value %= div;
	}
}
