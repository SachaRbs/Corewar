/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:47:17 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/30 17:02:15 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_token     *init_token(t_asm *p, t_type type)
{
    t_token		*token;

    if (!(token = malloc(sizeof(t_token))))
        ft_error("TOKEN MALLOC");
    token->str = NULL;
    token->type = type;
	if (token->type == SEPARATOR)				// A DELETE CEST POUR LE PRINT
		token->str = ft_strdup(",");
	if (token->type == NEWLINE)					// A DELETE CEST POUR LE PRINT
		token->str = ft_strdup("\\n");
	token->op_index = -1;
	token->dir_sz = 0;
    token->row = p->row;
    token->col = p->col;
    token->next = NULL;
    token->prev = NULL;
    return (token);
}

void		add_token(t_token **head, t_token *new)
{
	t_token		*tmp;

	// printf(YEL"ADD TOKEN [%s]\n"RESET, typestab[new->type]);
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
		printf("%15s [%s]\n", curr->str, typestab[curr->type]);
		curr = curr->next;
	}
	printf(RESET"\n");
}

void	free_tokens(t_token *head)
{
    t_token *tmp;;
    t_token *curr;

	tmp = head;
    while (tmp != NULL)
	{
        curr = tmp;
        tmp = tmp->next;
		if (curr->str)
			ft_strdel(&curr->str);
        free(curr);
		curr = NULL;
    }
}
