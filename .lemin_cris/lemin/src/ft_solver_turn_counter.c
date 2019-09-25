/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_turn_counter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:24:48 by cesar             #+#    #+#             */
/*   Updated: 2019/08/09 09:17:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_turn_counter_init(t_master *mstr, int *node_path, int flow)
{
	int i;
	int ants;
	int current_flow;
	int current_path_len;

	ants = mstr->ants;
	current_flow = 0;
	current_path_len = mstr->adjacency_mtx[node_path[0]][A_CURRENT_PATH_LEN];
	i = -1;
	while (++i < flow)
	{
		ants -= (mstr->adjacency_mtx[node_path[i]][A_CURRENT_PATH_LEN]
			- current_path_len) * current_flow;
		current_path_len =
			mstr->adjacency_mtx[node_path[i]][A_CURRENT_PATH_LEN];
		current_flow++;
	}
	if (ants > 0)
		return (ants);
	else
		return (-1);
}

static int	ft_end_of_search(t_master *mstr, int ants)
{
	if (ants != -1)
		return (0);
	ft_output_explained_turns(mstr, 0, 0);
	mstr->end_of_search = CERTAINLY;
	return (1);
}

void		ft_solver_turn_counter(t_master *mstr, int flow)
{
	int ants;
	int turns;

	ants = mstr->ants;
	mstr->skip = NOPE;
	turns = 0;
	ants = ft_turn_counter_init(mstr, mstr->node_path, flow);
	if (ft_end_of_search(mstr, ants))
		return ;
	if (ants != -1 && !mstr->end_of_search)
		turns = mstr->adjacency_mtx
			[mstr->node_path[flow - 1]][A_CURRENT_PATH_LEN] - 1;
	ft_output_explained_turns(mstr, ants, turns);
	while (ants > 0)
	{
		turns++;
		ants -= flow;
	}
	ft_output_explained_turns(mstr, -1, turns + 1);
	if (turns + 1 < mstr->turn_counter || flow == 1)
		mstr->turn_counter = turns + 1;
	else
		mstr->skip = CERTAINLY;
}
