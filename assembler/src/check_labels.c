/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:08:42 by epham             #+#    #+#             */
/*   Updated: 2019/10/28 19:12:35 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_labels(t_asm *env)
{
	t_label	*labels;
	t_label	*mentions;
	int		count;
	int		check;
	
	count = 0;
	check = 0;
	labels = env->tok_lab;
	mentions = env->mentions;
	while (mentions)
	{
		while (labels)
		{
			if (!ft_strcmp(mentions->name, labels->name))
			{
				count++;
				break ;
			}
			labels = labels->next;
		}
		mentions = mentions->next;
		labels = env->tok_lab;
		check++;
	}
	return (count == check ? 1 : -1);
}
