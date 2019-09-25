/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:36:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/11 16:31:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"
#include "libft/libft.h"
#include "output_explained.h"

static void		ft_path_cleaning(t_master *mstr, int queue_end, int end_node)
{
	int i;
	int j;

	mstr->node_queue[queue_end] = end_node;
	mstr->node_parents[queue_end] = queue_end - 1;
	i = queue_end + 1;
	j = 0;
	while (i--)
	{
		if (i == queue_end)
		{
			mstr->node_path[j++] = mstr->node_queue[i];
			queue_end = mstr->node_parents[i];
		}
	}
	queue_end = j - 1;
	j = -1;
	while (++j <= queue_end / 2)
		ft_swap(&mstr->node_path[j], &mstr->node_path[queue_end - j]);
	ft_output_explained(mstr, OC_OUTPUT_AUGMENTING_PATH);
}

static int		ft_node_is_to_loaded(t_master *mstr, int flow,
				int cur_node, int next_node)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if ((mtx[cur_node][A_LOADED] && flow == F_FLOW && !mtx[next_node][A_LOADED])
		|| (mtx[cur_node][A_LOADED] && mtx[next_node][A_LOADED]
		&& mtx[next_node][mstr->nodes + A_OPTIONS + cur_node] != ACTIVATED)
		|| mtx[next_node][A_VISIT_BACKFLOW] != DISCONNECTED)
		return (CERTAINLY);
	return (NOPE);
}

static int		ft_check_node(t_master *mstr, int cur_node,
								int next_node, int *queue)
{
	int **mtx;
	int flow;
	int visited_lvl;

	mtx = mstr->adjacency_mtx;
	flow = cur_node == mstr->start->node_number
		|| !(mtx[mstr->node_queue[mstr->node_parents[queue[0] - 1]]][A_LOADED]
		&& mtx[cur_node][A_LOADED])
		? F_FLOW : F_BACKFLOW;
	flow = mtx[next_node][mstr->nodes + A_OPTIONS + cur_node] == ACTIVATED
			? F_BACKFLOW : flow;
	if (ft_node_is_to_loaded(mstr, flow, cur_node, next_node))
		return (NOPE);
	visited_lvl = flow == F_FLOW ? A_VISIT_FLOW : A_VISIT_BACKFLOW;
	if (mtx[next_node][visited_lvl] == DISCONNECTED)
	{
		mstr->node_queue[queue[0] + queue[1]] = next_node;
		mstr->node_parents[queue[0] + queue[1]] = queue[0] - 1;
		mtx[next_node][A_VISIT_FLOW] = CERTAINLY;
		if (flow == F_BACKFLOW)
			mtx[next_node][A_VISIT_BACKFLOW] = CERTAINLY;
		return (SUCCESS);
	}
	return (NOPE);
}

static int		ft_check_is_allowed_next(t_master *mstr, int cur_node,
								int next_node, int parent_node)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (mtx[cur_node][mstr->nodes + A_OPTIONS + next_node] == ACTIVATED
		|| next_node == DISCONNECTED
		|| next_node == mstr->start->node_number
		|| next_node == parent_node)
		return (NOPE);
	return (SUCCESS);
}

int				ft_solver_paths_splitter(t_master *mstr, int **mtx,
								int cur_node, int end_node)
{
	int next_node;
	int i;
	int queue[2];

	ft_solver_path_splitter_init_stacks(mstr, cur_node, queue);
	while ((i = -1) && queue[1]--)
	{
		cur_node = mstr->node_queue[queue[0]++];
		while (++i < mtx[cur_node][A_LINKS_NB])
		{
			next_node = mtx[cur_node][A_OPTIONS + i];
			if (!ft_check_is_allowed_next(mstr, cur_node, next_node,
					mstr->node_queue[mstr->node_parents[queue[0] - 1]]))
				continue;
			if (next_node == end_node)
			{
				ft_path_cleaning(mstr, queue[0], end_node);
				return (SUCCESS);
			}
			if (ft_check_node(mstr, cur_node, next_node, queue))
				queue[1]++;
		}
	}
	return (DEAD_END);
}
