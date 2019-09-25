/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:26:31 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/07 20:29:53 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"

void	ft_alloc_ants(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->ants_array = (t_ants **)
		ft_memalloc(sizeof(t_ants *) * mstr->nb_ants)))
		ft_exit(mstr, ERROR_MALLOC);
	while (i < mstr->nb_ants)
	{
		if (!(mstr->ants_array[i] = (t_ants *)
			ft_memalloc(sizeof(t_ants) * mstr->nb_ants)))
			ft_exit(mstr, ERROR_MALLOC);
		mstr->ants_array[i]->ant_index = i;
		mstr->ants_array[i]->current_move = 0;
		mstr->ants_array[i]->current_node = FALSE;
		i++;
	}
}

void	ft_alloc_nodes(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->nodes_array = (t_nodes **)
		ft_memalloc(sizeof(t_nodes *) * mstr->nb_nodes)))
		ft_exit(mstr, ERROR_MALLOC);
	while (i < mstr->nb_nodes)
	{
		if (!(mstr->nodes_array[i] = (t_nodes *)
			ft_memalloc(sizeof(t_nodes))))
			ft_exit(mstr, ERROR_MALLOC);
		if (!(mstr->nodes_array[i]->pipes = (int *)
			ft_memalloc(sizeof(int) * mstr->nb_nodes)))
			ft_exit(mstr, ERROR_MALLOC);
		mstr->nodes_array[i]->nb_pipes = 0;
		mstr->nodes_array[i]->x_px = FALSE;
		mstr->nodes_array[i]->y_px = FALSE;
		mstr->nodes_array[i]->flag = NODE_USED;
		i++;
	}
}

void	ft_alloc_pipes(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->pipes_array = (t_pipes **)
		ft_memalloc(sizeof(t_pipes *) * mstr->nb_pipes)))
		ft_exit(mstr, ERROR_MALLOC);
	while (i < mstr->nb_pipes)
	{
		if (!(mstr->pipes_array[i] = (t_pipes *)
			ft_memalloc(sizeof(t_pipes))))
			ft_exit(mstr, ERROR_MALLOC);
		mstr->pipes_array[i]->active = PIPE_UNDEFINED;
		i++;
	}
}

void	ft_alloc_moves(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->moves_array = (t_moves **)
		ft_memalloc(sizeof(t_moves *) * (mstr->nb_movements + 1))))
		ft_exit(mstr, ERROR_MALLOC);
	mstr->moves_array[mstr->nb_movements] = NULL;
}

void	inizialization(t_master *mstr)
{
	mstr->start_index = FALSE;
	mstr->end_index = FALSE;
	mstr->current_node = 0;
	mstr->current_pipe = 0;
	mstr->current_move = 0;
	mstr->max_x = -2147483648;
	mstr->min_x = 2147483647;
	mstr->max_y = -2147483648;
	mstr->min_y = 2147483647;
	mstr->delay = 20;
	mstr->flag_move = TRUE;
	mstr->flag_exit = FALSE;
	ft_alloc_ants(mstr);
	ft_alloc_nodes(mstr);
	ft_alloc_pipes(mstr);
	ft_alloc_moves(mstr);
}
