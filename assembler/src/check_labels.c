/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:08:42 by epham             #+#    #+#             */
/*   Updated: 2019/10/29 17:37:20 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_label_lists(t_asm *env)
{
	t_label *head_labels;
	t_label *head_mentions;

	head_labels = env->tok_lab;
	head_mentions = env->mentions;
	printf("LABELS :\n");
	while (head_labels)
	{
		printf(" [%s %d:%d]", head_labels->name, head_labels->row, head_labels->col + 1);
		head_labels = head_labels->next;
	}
	printf("\n\nMENTIONS :\n");
	while (head_mentions)
	{
		printf(" [%s %d:%d]", head_mentions->name, head_mentions->row, head_mentions->col + 1);
		head_mentions = head_mentions->next;
	}
	printf("\n");
}

/*
***		SAVING LABELS AND MENTIONS TO ENV
*/

void	save_label(t_label **to, t_token *token)
{
	t_label *head;
	t_label *new;

	head = *to;
	printf("SAVING LABEL %s\n", token->str);
	if (!head)
		printf("FIRST LABEL TO BE SAVED\n");
	if (!(new = malloc(sizeof(t_label))))
		return ;
	new->name = ft_strdup(token->str);
	new->col = token->col;
	new->row = token->row;
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
	t_label	*labels;
	t_label	*mentions;
	int		check;
	
	labels = env->tok_lab;
	mentions = env->mentions;
	while (mentions)
	{
		check = 0;
		while (labels)
		{
			//TO REMOVE ONCE PARSING OF INDEX LABEL IS WITHOUT :
			if (mentions->name[0] == ':' && !ft_strcmp(mentions->name + 1, labels->name))
			{
				check = 1;
				break ;
			}
			//
			if (!ft_strcmp(mentions->name, labels->name))
			{
				check = 1;
				break ;
			}
			labels = labels->next;
		}
		if (check == 0)
			return (mentions);
		mentions = mentions->next;
		labels = env->tok_lab;
	}
	return (NULL);
}
