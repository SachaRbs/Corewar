/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:32:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/05 21:02:33 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			create_file(char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (fd);
}

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
	ft_printf(BOLDWHITE"Wrote output program to %s\n"RESET, p->filename);
	header = write_header(p);
	exec = write_exec(p);
	write(p->fd, header, SIZE);
	write(p->fd, exec, p->exec_sz);
	ft_strdel(&header);
	ft_strdel(&exec);
}
