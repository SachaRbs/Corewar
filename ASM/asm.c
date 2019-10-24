
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:23:36 by anonymous         #+#    #+#             */
/*   Updated: 2019/09/18 14:51:35 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char	*check_filename(char *file)
{
	char	*filename;
	char	*dot;
	char	*tmp;

	tmp = file;
	if ((tmp = ft_strrchr(tmp, '/')))
		file = tmp + 1;
	if (!(dot = ft_strchr(file, '.')))
		return (NULL);
	if (ft_strcmp(dot, ".s"))
		return (NULL);
	filename = ft_strnew(dot - file + 4);
	ft_strncpy(filename, file, (dot - file + 1));
	ft_strncpy(ft_strchr(filename, '.') + 1, "cor", 3);
	return (filename);
}

int		ft_readline(int fd, char **str, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*ptr;
	ssize_t sz;

	while (!ft_strchr(*str, '\n') && (sz = read(fd, buffer, BUFF_SIZE)) > 0)
		if (!(*str = ft_strnjoin(*str, buffer, sz)))
			return (-1);
	sz = 0;
	while ((*str)[sz] && (*str)[sz] != '\n')
		++sz;
	if ((*line = ft_strndup(*str, sz)) == NULL)
		return (-1);
	if ((*str)[sz] == '\n')
		++sz;
	ptr = *str;
	if ((*str = ft_strdup(ptr + sz)) == NULL)
		return (-1);
	free(ptr);
	// printf("read %zu ", sz);
	// printf(GRN"[%s]\n"RESET, *line);
	return (sz > 0 ? sz : 0);
}

int		main(int argc, char **argv)
{
	t_asm	*p;
	int		fd;

	if (argc != 2)
		ft_error("usage: ./asm champion.s");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(1);
	p = init_struct(fd);
	p->filename = check_filename(argv[1]);
	parse(p);
}
