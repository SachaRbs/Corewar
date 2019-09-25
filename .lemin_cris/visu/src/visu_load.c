/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:38:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/11 18:16:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"

char	g_path_from_visu_textures[12][150] = {
	{"resources_visual/background.jpg"},
	{"resources_visual/home.png"},
	{"resources_visual/end.png"},
	{"resources_visual/tend4.png"},
	{"resources_visual/ballon.png"},
	{"resources_visual/bike.png"},
	{"resources_visual/car.png"},
	{"resources_visual/ship.png"},
	{"resources_visual/submarine.png"},
	{"resources_visual/train.png"},
	{"resources_visual/van.png"},
	{"resources_visual/velero.png"},
};

char	g_path_from_git_textures[12][150] = {
	{"visu/resources_visual/background.jpg"},
	{"visu/resources_visual/home.png"},
	{"visu/resources_visual/end.png"},
	{"visu/resources_visual/tend4.png"},
	{"visu/resources_visual/ballon.png"},
	{"visu/resources_visual/bike.png"},
	{"visu/resources_visual/car.png"},
	{"visu/resources_visual/ship.png"},
	{"visu/resources_visual/submarine.png"},
	{"visu/resources_visual/train.png"},
	{"visu/resources_visual/van.png"},
	{"visu/resources_visual/velero.png"},
};

void	load_start_end_textures(t_master *mstr)
{
	if (!(mstr->start = (t_texture*)ft_memalloc(sizeof(t_texture))))
		ft_exit(mstr, ERROR_MALLOC);
	init_texture(mstr->start);
	if (load_texture_from_file(mstr, mstr->start,
	g_path_from_visu_textures[1]) == FALSE)
		if (load_texture_from_file(mstr, mstr->start,
		g_path_from_git_textures[1]) == FALSE)
			ft_exit(mstr, LOAD_VISU);
	mstr->start->width = 100;
	mstr->start->height = 100;
	if (!(mstr->finish = (t_texture*)ft_memalloc(sizeof(t_texture))))
		ft_exit(mstr, ERROR_MALLOC);
	init_texture(mstr->finish);
	if (load_texture_from_file(mstr, mstr->finish,
	g_path_from_visu_textures[2]) == FALSE)
		if (load_texture_from_file(mstr, mstr->finish,
		g_path_from_git_textures[2]) == FALSE)
			ft_exit(mstr, LOAD_VISU);
	mstr->finish->width = 100;
	mstr->finish->height = 100;
}

void	load_background_node_textures(t_master *mstr)
{
	if (!(mstr->background = (t_texture*)ft_memalloc(sizeof(t_texture))))
		ft_exit(mstr, ERROR_MALLOC);
	init_texture(mstr->background);
	if (load_texture_from_file(mstr, mstr->background,
	g_path_from_visu_textures[0]) == FALSE)
		if (load_texture_from_file(mstr, mstr->background,
		g_path_from_git_textures[0]) == FALSE)
			ft_exit(mstr, LOAD_VISU);
	mstr->background->width = S_WIDTH;
	mstr->background->height = S_HEIGHT;
	if (!(mstr->node = (t_texture*)ft_memalloc(sizeof(t_texture))))
		ft_exit(mstr, ERROR_MALLOC);
	init_texture(mstr->node);
	if (load_texture_from_file(mstr, mstr->node,
	g_path_from_visu_textures[3]) == FALSE)
		if (load_texture_from_file(mstr, mstr->node,
		g_path_from_git_textures[3]) == FALSE)
			ft_exit(mstr, LOAD_VISU);
	mstr->node->width = 70;
	mstr->node->height = 70;
}

void	vs_load(t_master *mstr)
{
	int		i;

	i = 4;
	if (!(mstr->textures = (t_texture**)ft_memalloc(sizeof(t_texture*) * 8)))
		ft_exit(mstr, ERROR_MALLOC);
	while (i < 12)
	{
		if (!(mstr->textures[i - 4] = (t_texture*)
		ft_memalloc(sizeof(t_texture))))
			ft_exit(mstr, ERROR_MALLOC);
		init_texture(mstr->textures[i - 4]);
		if (load_texture_from_file(mstr, mstr->textures[i - 4],
		g_path_from_visu_textures[i]) == FALSE)
			if (load_texture_from_file(mstr, mstr->textures[i - 4],
			g_path_from_git_textures[i]) == FALSE)
				ft_exit(mstr, LOAD_VISU);
		mstr->textures[i - 4]->width = 100;
		mstr->textures[i - 4]->height = 100;
		i++;
	}
	load_background_node_textures(mstr);
	load_start_end_textures(mstr);
}
