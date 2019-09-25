/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage_get_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:49:53 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/11 16:07:09 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"

t_line_info			*ft_storage_get_line(t_master *mstr, int line_nb)
{
	int				reduc_ind;
	t_line_info		*entry;
	t_storage		*storage_start;

	storage_start = mstr->storage_start;
	if (!storage_start)
		return (0);
	reduc_ind = line_nb % BATCH_MALLOC_SIZE;
	while (storage_start->next && line_nb >= BATCH_MALLOC_SIZE)
	{
		line_nb -= BATCH_MALLOC_SIZE;
		storage_start = storage_start->next;
	}
	if (line_nb >= BATCH_MALLOC_SIZE || line_nb < 0)
		ft_exit(FAIL_LINE_GRAB, mstr);
	entry = &(storage_start->entry[reduc_ind]);
	return (entry);
}
