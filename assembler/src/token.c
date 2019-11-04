/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:47:17 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/04 18:45:07 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_token		*init_token(t_asm *p, t_type type)
{
	t_token		*token;

	if (!(token = malloc(sizeof(t_token))))
		ft_error("TOKEN MALLOC");
	token->str = NULL;
	token->type = type;
	token->value = 0;
	token->ocp = 0;
	token->op_index = -1;
	token->byte_pos = 0;
	token->byte_sz = 0;
	token->exec_sz = 0;
	token->row = p->row;
	token->col = p->col;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

void		get_value(t_token **token)
{
	if ((*token)->type == REGISTER)
		(*token)->value = ft_atol(ft_strchr((*token)->str, 'r') + 1);
	else if ((*token)->type == INDEX)
		(*token)->value = ft_atol((*token)->str);
	else if ((*token)->type == DIRECT)
		(*token)->value = ft_atol((*token)->str);
}

void		add_token(t_token **head, t_token *new)
{
	t_token		*tmp;

	if (new->type == REGISTER || new->type == INDEX || new->type == DIRECT)
		get_value(&new);
	if (!(*head))
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void		print_token(t_token *head)
{
	t_token		*curr;

	curr = head;
	printf(YEL"\n\nTOKENS:\n");
	while (curr)
	{
		printf("%15s [%s]\n", curr->str, g_typestab[curr->type]);
		curr = curr->next;
	}
	printf(RESET"\n");
}
