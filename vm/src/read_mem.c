/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:59:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/06 14:40:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

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

void				*ft_memcpy_mod(void *restrict dst,
					const void *restrict src, int add, int size)
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

/*
***		THE SECOND FUNCTION NEVER MOVES proc->read [GET = 0]
*/

int					read_mem(t_vm *vm, int address, int size)
{
	int		val;

	val = 0;
	ft_memcpy_mod(&val, vm->mem, address, size);
	return (big_endian(val, size));
}

/*
***		THE SECOND FUNCTION ALWAYS MOVES proc->read [GET = 1]
*/

int					read_mem_and_move_pc(t_vm *vm,
					int address, int size, t_proc *proc)
{
	int		val;

	val = 0;
	ft_memcpy_mod(&val, vm->mem, address, size);
	proc->read += size;
	return (big_endian(val, size));
}
