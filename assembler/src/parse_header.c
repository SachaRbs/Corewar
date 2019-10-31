/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:38:19 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/30 18:50:12 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*parse_multiline(t_asm *p, char **line)
{
	size_t	size;
	char	*str;
	char	*end;

	str = ft_strdup(*line + p->col);
	while (ft_readline(p->fd, &p->str, line) > 0
	&& (!(end = ft_strchr(*line, '"'))))
	{
		str = ft_strjoin(str, *line);
		p->row++;
	}
	p->row++;
	size = ft_strlen(str);
	str = ft_strjoin(str, *line);
	p->col = 0;
	while ((*line)[p->col] && (*line)[p->col] != '"')
		p->col++;
	return (ft_strsub(str, 0, p->col + size));
}

void	parse_champion(t_asm *p, char **line)
{
	size_t		start;

	start = 0;
	while (is_whitespace((*line)[p->col]) && (*line)[p->col])
		p->col++;
	if ((*line)[p->col] == '"')
	{
		p->col++;
		start = p->col;
		if (ft_strchr(*line + p->col, '"'))
		{
			while ((*line)[p->col] && (*line)[p->col] != '"')
				p->col++;
			p->champ = ft_strsub(*line + start, 0, p->col - start);
		}
		else
			p->champ = parse_multiline(p, line);
	}
	else
		ft_lexerror(p);
	// printf(GRN"%s\n"RESET, p->champ);
	if (!p->champ || ft_strlen(p->champ) > PROG_NAME_LENGTH)
		ft_error("CHAMPION NAME TOO LONG");
}

void	parse_comment(t_asm *p, char **line)
{
	size_t		start;

	start = 0;
	while (is_whitespace((*line)[p->col]) && (*line)[p->col])
		p->col++;
	if ((*line)[p->col] == '"')
	{
		p->col++;
		start = p->col;
		if (ft_strchr(*line + p->col, '"'))
		{
			while ((*line)[p->col] && (*line)[p->col] != '"')
				p->col++;
			p->comment = ft_strsub(*line + start, 0, p->col - start);
		}
		else
			p->comment = parse_multiline(p, line);
	}
	// printf(GRN"%s\n"RESET, p->comment);
	if (!p->comment || ft_strlen(p->comment) > COMMENT_LENGTH)
		ft_error("CHAMPION COMMENT TOO LONG");
}

void	parse_header(t_asm *p, t_token *new, char **line)
{
	if (!ft_strncmp(new->str, NAME_CMD_STRING, 5))
	{
		if (p->champ && new->type == NAME)
			ft_error("HEADER ALREADY EXISTS");
		new->type = NAME;
		parse_champion(p, line);
		if ((*line)[p->col] == '"')
			p->col++;
	}
	else if (!ft_strncmp(new->str, COMMENT_CMD_STRING, 8))
	{
		if (p->comment && new->type == COMMENT)
			ft_error("HEADER ALREADY EXISTS");
		new->type = COMMENT;
		parse_comment(p, line);
		if ((*line)[p->col] == '"')
			p->col++;
	}
	else
		ft_lexerror(p);
}
