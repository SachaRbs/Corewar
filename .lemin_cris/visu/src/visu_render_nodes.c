/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:13:58 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/11 18:30:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static float	ratio(t_master *mstr, char exe, int i)
{
	float ratio;

	if (exe == 'x')
	{
		if (mstr->max_x == mstr->min_x)
			ratio = 0.5;
		else
			ratio = (float)((double)(mstr->nodes_array[i]->x - mstr->min_x)
				/ (double)(mstr->max_x - mstr->min_x));
	}
	if (exe == 'y')
	{
		if (mstr->max_y == mstr->min_y)
			ratio = 0.5;
		else
			ratio = (float)((double)(mstr->nodes_array[i]->y - mstr->min_y)
				/ (double)(mstr->max_y - mstr->min_y));
	}
	return (ratio);
}

void			render_nodes(t_master *mstr)
{
	int i;

	i = 0;
	while (i < mstr->nb_nodes)
	{
		if (mstr->nodes_array[i]->x_px == FALSE)
		{
			mstr->nodes_array[i]->x_px = ((float)S_WIDTH * 0.05)
				+ (ratio(mstr, 'x', i) * (float)S_WIDTH * 0.85);
		}
		if (mstr->nodes_array[i]->y_px == FALSE)
		{
			mstr->nodes_array[i]->y_px = ((float)S_HEIGHT * 0.05)
				+ (ratio(mstr, 'y', i) * (float)S_HEIGHT * 0.85);
		}
		if (mstr->nodes_array[i]->flag == NODE_USED)
		{
			render_texture(mstr, mstr->node,
						mstr->nodes_array[i]->x_px - 30,
						mstr->nodes_array[i]->y_px - 50);
		}
		i++;
	}
}
