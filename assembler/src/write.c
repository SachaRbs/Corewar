/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/04 12:26:52 by epham            ###   ########.fr       */
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

/*
*** n = nth byte
*** int x = (number >> (8*n)) & 0xff;
*/

void		write_byte(char *byte, int pos, int value, size_t size)
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

void		write_to_file(t_asm *p)
{
	char	*header;
	char	*exec;

	header = NULL;
	exec = NULL;
	printf(BOLDWHITE"Wrote output program to %s\n"RESET, p->filename);
	header = write_header(p);
	exec = write_exec(p);
	write(p->fd, header, SIZE);
	write(p->fd, exec, p->exec_sz);
	ft_strdel(&header);
	ft_strdel(&exec);
}
