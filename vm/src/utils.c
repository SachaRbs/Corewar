/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/15 19:10:21 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

int16_t			reverser_16(int16_t a)
{
	return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}

int32_t			reverser_32(int32_t a)
{
	int32_t		tmp;

	tmp = 0;
	tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
	tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
	return (tmp);
}

unsigned int	big_endian(unsigned int num, int n)
{
	if (n == 1)
		return (num);
	else if (n == 2)
		return (reverser_16(num));
	else if (n == 4)
		return (reverser_32(num));
	return (-1);
}

void			print_memory(unsigned char *mem)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		printf("%02hhx ", mem[i]);
	printf("\n");
}
