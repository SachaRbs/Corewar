/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/30 11:03:21 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdint.h>

char		*ft_itoa_bse(unsigned int n, int base, int len)
{
	char	*str;
	char	*sbase;

	sbase = "0123456789abcdef";
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = sbase[n % base];
		n /= base;
		len--;
	}
	return (str);
}

int			write_bytes(int value, int byte)
{
	if (byte == 4)
	{
		return (((value >> 24) & 0xff) |
			((value << 8) & 0xff0000) |
			((value >> 8) & 0xff00) |
			((value << 24) & 0xff000000));
	}
	if (byte == 3)
	{
		return (((value << 16) & 0xff0000) |
			((value << 0) & 0xff00) |
			((value >> 16) & (0xff)));
	}
	else if (byte == 2)
		return (value >> 8) | (value << 8);
	else
		return (value);
}


void	int32_to_bytecode(char *data,
							int32_t pos,
							int32_t value,
							size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void		write_header(t_asm *p)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2048);
	// write(ret, "\x00\xea\x83\xf3", sizeof(int));
	int32_to_bytecode(ret, 0, COREWAR_EXEC_MAGIC, 4);
	// ft_memcpy(&ret[4], p->champ, ft_strlen(p->champ));
	write(p->fd, ret, 10);
}

void		write_to_file(t_asm *p)
{
	write_header(p);
}

// unsigned int value = 255;

// buffer[0] = (value >> 24) & 0xFF;
// buffer[1] = (value >> 16) & 0xFF;
// buffer[2] = (value >> 8) & 0xFF;
// buffer[3] = value & 0xFF;

// union {
//     unsigned int integer;
//     unsigned char byte[4];
// } temp32bitint;

// temp32bitint.integer = value;
// buffer[8] = temp32bitint.byte[3];
// buffer[9] = temp32bitint.byte[2];
// buffer[10] = temp32bitint.byte[1];
// buffer[11] = temp32bitint.byte[0];