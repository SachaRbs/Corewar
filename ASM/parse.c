/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:58:55 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/23 14:53:03 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void	parse_token(t_asm *p, char **line)
{
	
}

void	parse(t_asm *p)
{
	static char		*str;
	char 			*line;

	str = ft_strnew(1);
	while ((ft_readline(p->fd, &p->str, &line) > 0))
	{
		p->col = 0;
		skip_whitespaces(&line);
		skip_comment(&line);
		if (line[p->col])
			parse_token(p, &line);
    	p->row++;
	}
}
