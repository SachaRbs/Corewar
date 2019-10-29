/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:36:24 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/17 17:49:09 by yoribeir         ###   ########.fr       */
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
	p->file = ft_strnew(0);
	p->champ = NULL;
	p->comment = NULL;
	p->f_header = 0;
	p->str = ft_strnew(1);
	p->byte_pos = 0;
	p->row = 1;
	p->col = 1;
	p->syntax_state = 0;
	p->tokens = NULL;
	p->labels = NULL;
	p->tok_lab = NULL;
	p->mentions = NULL;
	return (p);
}
