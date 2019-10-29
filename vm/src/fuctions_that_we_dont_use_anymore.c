/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuctions_that_we_dont_use_anymore.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:20:13 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/29 15:28:37 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

