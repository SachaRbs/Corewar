/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:01:15 by epham             #+#    #+#             */
/*   Updated: 2019/11/06 13:23:49 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*check_filename(char *file)
{
	char	*filename;
	char	*dot;

	if (!(dot = ft_strrchr(file, '.')))
		return (NULL);
	if (ft_strcmp(dot, ".s"))
		return (NULL);
	filename = ft_strnew(dot - file + 4);
	ft_strncpy(filename, file, (dot - file));
	if (!ft_strlen(filename))
		ft_error("file error");
	ft_strncpy(filename + ft_strlen(filename), ".cor", 4);
	return (filename);
}

int		ft_readline(int fd, char **str, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*ptr;
	char	*tmp;
	ssize_t sz;

	tmp = *str;
	while (!ft_strchr(*str, '\n') && (sz = read(fd, buffer, BUFF_SIZE)) > 0)
		if (!(*str = ft_strnjoinfree(*str, buffer, sz)))
			return (-1);
	sz = 0;
	while ((*str)[sz] && (*str)[sz] != '\n')
		++sz;
	if ((*line = ft_strndup(*str, sz + 1)) == NULL)
		return (-1);
	if ((*str)[sz] == '\n')
		++sz;
	ptr = *str;
	if ((*str = ft_strdup(ptr + sz)) == NULL)
		return (-1);
	free(ptr);
	return (sz > 0 ? sz : 0);
}

int		main(int argc, char **argv)
{
	t_asm	*p;
	int		fd;
	char	*filename;

	if (argc != 2)
		ft_error("usage: ./asm champion.s");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_error("Unable to open file");
		exit(1);
	}
	if (!(filename = check_filename(argv[1])))
		ft_error("file error");
	p = init_struct(fd, filename, argv[1]);
	parse(p);
	if (check_token(p) == -1)
		exit(1);
	if ((p->fd = create_file(filename)) == -1)
		ft_error("file creation error");
	write_to_file(p);
	free_asm(p);
	return (0);
}
