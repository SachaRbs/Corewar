/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:18:12 by epham             #+#    #+#             */
/*   Updated: 2019/11/04 12:18:17 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_asm	*init_struct(int fd)
{
	t_asm	*p;

	if (!(p = malloc(sizeof(t_asm))))
		exit(1);
	p->fd = fd;
	p->filename = NULL;
	p->file = NULL;
	p->champ = NULL;
	p->comment = NULL;
	p->f_header = 0;
	p->str = ft_strnew(1);
	p->exec_sz = 0;
	p->byte_pos = 0;
	p->row = 1;
	p->col = 1;
	p->syntax_state = 0;
	p->tokens = NULL;
	p->labels = NULL;
	p->mentions = NULL;
	return (p);
}
