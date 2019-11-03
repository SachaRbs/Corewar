/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/03 23:49:26 by epham            ###   ########.fr       */
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

char		*write_header(t_asm *p)
{
	char	*ret;

	ret = malloc(sizeof(char) * SIZE);
	ft_memset(ret, 0, SIZE);
	p->byte_pos = 0;
	write_byte(ret, p->byte_pos, COREWAR_EXEC_MAGIC, 4);
	p->byte_pos += 4;
	ft_memcpy(&ret[p->byte_pos], p->champ, ft_strlen(p->champ));
	p->byte_pos += PROG_NAME_LENGTH + 4;
	write_byte(ret, p->byte_pos, p->exec_sz, 4);
	p->byte_pos += 4;
	ft_memcpy(&ret[p->byte_pos], p->comment, ft_strlen(p->comment));
	p->byte_pos += COMMENT_LENGTH + 4;
	return (ret);
}

void		write_to_file(t_asm *p)
{
	char	*header;
	char	*exec;

	header = NULL;
	exec = NULL;
	printf(BOLDWHITE"Wrote output program to %s\n"RESET, p->filename);
	// get_exec_sz(p);
	// if (p->exec_sz > 682)
	// {
		// printf("EXEC SIZE TOO BIG\n");
		// exit(1);
	// }
	header = write_header(p);
	exec = write_exec(p);
	write(p->fd, header, SIZE);
	write(p->fd, exec, p->exec_sz);
}
