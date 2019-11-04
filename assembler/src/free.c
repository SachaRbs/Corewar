/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:52:05 by epham             #+#    #+#             */
/*   Updated: 2019/11/04 12:17:18 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
***		FREE TOKENS
*/

void		free_tokens(t_token *head)
{
	t_token *tmp;
	t_token *curr;

	tmp = head;
	while (tmp != NULL)
	{
		curr = tmp;
		tmp = tmp->next;
		if (curr->str)
			free(curr->str);
		curr->str = NULL;
		free(curr);
		curr = NULL;
	}
}

/*
***		FREE LABELS
*/

void		free_labels(t_label *labels)
{
	t_label *tmp;
	t_label *curr;

	tmp = labels;
	while (tmp != NULL)
	{
		curr = tmp;
		tmp = tmp->next;
		if (curr->name)
			free(curr->name);
		curr->name = NULL;
		free(curr);
		curr = NULL;
	}
}

/*
***		FREE ENV
*/

void		free_asm(t_asm *env)
{
	if (env->filename)
		free(env->filename);
	if (env->champ)
		free(env->champ);
	if (env->comment)
		free(env->comment);
	if (env->str)
		free(env->str);
	if (env->tokens)
		free_tokens(env->tokens);
	if (env->labels)
		free_labels(env->labels);
	if (env->mentions)
		free_labels(env->mentions);
	free(env);
}
