/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:10:56 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/17 17:49:22 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*parse_multiline(t_asm *p, char *line)
{
	size_t	size;
	char	*buffer;
	char	*str;
	char	*end;

	str = ft_strdup(line + p->col);
	while (ft_readline(p->fd, &p->str, &buffer) > 0 && (!(end = ft_strchr(buffer, '"'))))
	{
		str = ft_strjoin(str, buffer);
		p->row++;
	}
	size = ft_strlen(str);
	str = ft_strjoin(str, buffer);
	p->col = 0;
	while (buffer[p->col] && buffer[p->col] != '\n')
		p->col++;
	if (buffer[p->col] == '\n')
	{
		p->col++;
		p->row++;
	}
	return (ft_strsub(str, 0, p->col + size - 2));
}

void	parse_champion(t_asm *p, char *line)
{
	size_t		start;

	start = 0;
    while (is_whitespace(line[p->col]) && line[p->col])
        p->col++;
    if (line[p->col] == '"')
    {
        p->col++;
		start = p->col;
		if (ft_strchr(line + p->col, '"'))
		{
			while (line[p->col] && line[p->col] != '"')
				p->col++;
			p->champ = ft_strsub(line + start, 0, p->col - start);
		}
		else
			p->champ = parse_multiline(p, line);
    }
	else
		ft_lexerror(p);
	printf(GRN"[%s]\n"RESET, p->champ);
    if (p->champ && ft_strlen(p->champ) > PROG_NAME_LENGTH)
        ft_error("CHAMPION NAME TOO LONG");
}

void	parse_comment(t_asm *p, char *line)
{
	size_t		start;

	start = 0;
    while (is_whitespace(line[p->col]) && line[p->col])
        p->col++;
    if (line[p->col] == '"')
    {
        p->col++;
		start = p->col;
		if (ft_strchr(line + p->col, '"'))
		{
			while (line[p->col] && line[p->col] != '"')
				p->col++;
			p->comment = ft_strsub(line + start, 0, p->col - start);
		}
		else
			p->comment = parse_multiline(p, line);
    }
	printf(GRN"[%s]\n"RESET, p->comment);
    if (ft_strlen(p->comment) > COMMENT_LENGTH)
        ft_error("CHAMPION COMMENT TOO LONG");
}

void	parse_header(t_asm *p, t_token *new, char *line)
{
	if (!ft_strncmp(new->str, NAME_CMD_STRING, 5))
	{
		if (p->champ && new->type == NAME)
			ft_error("HEADER ALREADY EXISTS");
		new->type = NAME;
		parse_champion(p, line);
		if (line[p->col] == '"')
			p->col++;
	}
	else if (!ft_strncmp(new->str, COMMENT_CMD_STRING, 8))
	{
		if (p->comment && new->type == COMMENT)
			ft_error("HEADER ALREADY EXISTS");
		new->type = COMMENT;
		parse_comment(p, line);
		if (line[p->col] == '"')
			p->col++;
	}
	else
		ft_error("BAD COMMAND");
}
