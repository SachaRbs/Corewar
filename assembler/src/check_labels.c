/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:08:42 by epham             #+#    #+#             */
/*   Updated: 2019/11/05 20:56:10 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_label_lists(t_asm *env)
{
	t_label *head_labels;
	t_label *head_mentions;

	head_labels = env->labels;
	head_mentions = env->mentions;
	ft_printf("LABELS :\n");
	while (head_labels)
	{
		ft_printf(" [%s %d:%d]",
		head_labels->name, head_labels->row, head_labels->col + 1);
		head_labels = head_labels->next;
	}
	ft_printf("\n\nMENTIONS :\n");
	while (head_mentions)
	{
		ft_printf(" [%s %d:%d]",
		head_mentions->name, head_mentions->row, head_mentions->col + 1);
		head_mentions = head_mentions->next;
	}
	ft_printf("\n");
}

/*
***		SAVING LABELS AND MENTIONS TO ENV
*/

void		save_label(t_label **to, t_token *token)
{
	t_label *head;
	t_label *new;

	head = *to;
	if (!(new = malloc(sizeof(t_label))))
		return ;
	new->name = ft_strdup(token->str);
	new->col = token->col;
	new->row = token->row;
	new->byte_pos = 0;
	new->from = token;
	new->next = NULL;
	if (!(*to))
		*to = new;
	else
	{
		while ((*to)->next)
			*to = (*to)->next;
		(*to)->next = new;
		*to = head;
	}
}

/*
***		CHECK THAT ALL MENTIONS OF LABELS ARE ACTUALLY DECLARED
*/

t_label		*check_labels(t_asm *env)
{
	t_label	*lab;
	t_label	*men;
	int		check;

	lab = env->labels;
	men = env->mentions;
	while (men)
	{
		check = 0;
		while (lab)
		{
			if (!ft_strcmp(men->name, lab->name))
			{
				check = 1;
				men->from->value = lab->from->byte_pos - men->from->byte_pos;
				break ;
			}
			lab = lab->next;
		}
		if (check == 0)
			return (men);
		men = men->next;
		lab = env->labels;
	}
	return (NULL);
}
