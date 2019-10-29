/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/29 19:20:49 by sarobber         ###   ########.fr       */
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
	return(add);
}

void	*ft_memcpy_mod(void *restrict dst, const void *restrict src, int add, int size)
{
	int				i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = -1;
	while (++i < size)
		dst1[i] = src1[mod_address(add + i)];
	return (dst);
}

int	read_mem(t_vm *vm, int address, int size, int get, t_proc *proc)
{
	int		val;

	val = 0;
	ft_memcpy_mod(&val, vm->mem, address, size);
	if (get)
		proc->read += size;
	return (big_endian(val, size));
}




































// unsigned int	get_instruction(t_vm *vm, int size, unsigned int *pc)
// {
// 	int		val;
// 	int		address;

// 	val = 0;
// 	if (*pc + size >= MEM_SIZE)
// 		address = 
// 	ft_memcpy(&val, &(vm->mem[*pc % MEM_SIZE]), size);
// 	else
// 		val = -1;
// 	*pc += size;
// 	return (big_endian(val, size));
// }


// int	read_mem(t_vm *vm, int address, int bytes)
// {
// 	int value;
// 	int multi;
// 	int temp1;
// 	int temp2;
// 	int i;
// 	int j;
// 	int neg;

// 	i = 0;
// 	j = 0;
// 	value = 0;
// 	bytes *= 2;
// 	neg = vm->mem[address] > 239 ? -1 : 1;
// 	while (i < bytes)
// 	{
// 		temp1 = neg == -1 ? 15 - (vm->mem[address + j] / 16) : (vm->mem[address + j]) / 16;
// 		temp2 = neg == -1 ? 15 - (vm->mem[address + j] % 16) : vm->mem[address + j] % 16;
// 		multi = temp1 * ft_power(16, (bytes) - 1 - i);
// 		value += multi;
// 		i++;
// 		multi = temp2 * ft_power(16, (bytes) - 1 - i);
// 		value += multi;
// 		i++;
// 		j++;
// 	}
// 	value += neg == -1 ? 1 : 0;
// 	return(neg * value);
// }

