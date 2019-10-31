/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/31 16:55:27 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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

// n = nth byte
// int x = (number >> (8*n)) & 0xff;

void	write_byte(char *byte, int pos, int value, size_t size)
{
	char	i;

	i = 0;
	while (size)
	{
		byte[pos + size - 1] = (char)((value >> i) & 255);
		i += 8;
		size--;
	}
}

#define SIZE 2192

void		write_header(t_asm *p)
{
	char	*ret;
	int		pos;

	ret = malloc(sizeof(char) * SIZE);
	ft_memset(ret, 0, SIZE);
	pos = 0;
	write_byte(ret, pos, COREWAR_EXEC_MAGIC, 4);
	pos += 4;
	ft_memcpy(&ret[pos], p->champ, ft_strlen(p->champ));
	pos += PROG_NAME_LENGTH + 4;
	write_byte(ret, pos, 0x16, 4);
	pos += 4;
	ft_memcpy(&ret[pos], p->comment, ft_strlen(p->comment));
	pos += COMMENT_LENGTH + 4;
	write(p->fd, ret, SIZE);
}

void		write_to_file(t_asm *p)
{
	printf(BOLDWHITE"Wrote output to %s\n"RESET, p->filename);
	write_header(p);
}
