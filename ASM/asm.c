
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
	printf("read %zu ", sz);
	printf(GRN"[%s]\n"RESET, *line);
	return (sz > 0 ? sz : 0);
}

void	get_function(t_asm *p, char **line)
{
	int i;

	i = 0;
	skip_whitespaces(line);
	while ((*line)[i] && !is_whitespace((*line)[i]) && (*line)[i] != ':' &&
		   (*line)[i] != '%')
		i++;
	if ((*line)[i] == ':')
	{
		add_label(p, *line);
		*line += i + 1;
    	get_function(p, line);
    }
	else if ((*line)[i] == '%' || is_whitespace((*line)[i]))
	{
        if (check_instruction(p, line, i))
		{
			// get_instruction(p, line, i);
		}
    }
}

void	read_main(t_asm *p)
{
	static char		*str;
	char 			*buffer;

	str = ft_strnew(1);
	while ((ft_readline(p->fd, &p->str, &buffer) > 0))
	{
		get_function(p, &buffer);
    	p->row++;
	}
    print_labels(p->labels);
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
	// read_header(p);
	// read_main(p);
}
