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

#include "includes/asm.h"

t_asm	*init_struct(int fd)
{
	t_asm	*p;

	if (!(p = malloc(sizeof(t_asm))))
		exit(1);
	p->fd = fd;
	p->file = ft_strnew(0);
	p->champ = 0;
	p->comment = 0;
	p->f_header = 0;
	p->str = ft_strnew(1);
        p->byte_pos = 0;
	p->row = 0;
	p->col = 0;
	p->syntax_state = 0;
	p->op_tab = g_op_tab;
	p->labels = NULL;
	if (!(p->header = malloc(sizeof(header_t))))
		exit(1);
	return (p);
}
