/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:14:23 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/09 15:13:18 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	render_pipes(t_master *mstr)
{
	int		i;

	i = 0;
	while (i < mstr->nb_pipes)
	{
		if (mstr->pipes_array[i]->active == PIPE_ACTIVE)
		{
			if (SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF)
			== FALSE || SDL_RenderDrawLine(mstr->render,
			mstr->nodes_array[mstr->pipes_array[i]->node1_index]->x_px,
			mstr->nodes_array[mstr->pipes_array[i]->node1_index]->y_px,
			mstr->nodes_array[mstr->pipes_array[i]->node2_index]->x_px,
			mstr->nodes_array[mstr->pipes_array[i]->node2_index]->y_px)
			== FALSE)
				ft_exit(mstr, RENDER_VISU);
		}
		i++;
	}
}
