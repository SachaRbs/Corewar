
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:23:36 by anonymous         #+#    #+#             */
/*   Updated: 2019/09/18 14:51:35 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*check_filename(char *file)
{
	char	*filename;
	char	*dot;

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
		if (!(*str = ft_strnjoin_free(*str, buffer, sz)))
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
	free((void *)ptr);
	return (sz > 0 ? sz : 0);
}

void	get_function(t_asm *p, char **line)
{
	int		i;

	i = 0;
	if (**line == '.')
	{
		get_champion(p, *line);
		get_comment(p, *line);
	}
	else if (p->champ && p->comment)
	{
		while ((*line)[i] && !is_whitespace((*line)[i]) && (*line)[i] != ':'
		&& (*line)[i] != '%')
			i++;
		if ((*line)[i] == ':')
		{
			p->f_label = 1;
			printf("line = %s\n", *line);
			add_label(p, line);
			printf("line = %s\n", *line);
		}
		else if ((*line)[i] == '%')
		{

		}
	}
}

void	read_file(t_asm *p)
{
	static char *str;
	char		*buffer;

	str = ft_strnew(1);
	while ((ft_readline(p->fd, &str, &buffer) > 0))
	{
		printf("[%s]\n", buffer);
		get_function(p, &buffer);
		p->linecount++;
	}
	print_labels(p->labels);
	close(p->fd);
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
	read_file(p);
}
