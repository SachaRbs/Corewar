/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:47:17 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/24 16:55:06 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

t_token     *init_token(t_asm *p, t_type type)
{
    t_token		*token;

    if (!(token = malloc(sizeof(t_token))))
        ft_error("TOKEN MALLOC");
    token->str = NULL;
    token->type = type;
    token->row = p->row;
    token->col = p->col;
    token->next = NULL;
    return (token);
}

void		add_token(t_token **head, t_token *new)
{
	t_token		*tmp;

	printf("ADD TOKEN\n");
	if (!(*head))
	{
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		print_token(t_token *head)
{
	t_token		*curr;

	curr = head;
	printf(YEL"TOKENS:\n");
	while (curr)
	{
		printf("%15s [%s]\n", curr->str, typestab[curr->type]);
		curr = curr->next;
	}
	printf(RESET"\n");
}