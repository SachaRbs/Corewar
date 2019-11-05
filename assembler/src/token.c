/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:47:17 by yoribeir          #+#    #+#             */
/*   Updated: 2019/11/05 19:28:34 by yoribeir         ###   ########.fr       */
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

long		check_value(t_asm *p, char *str)
{
	size_t	str_len;
	size_t	size;
	long	value;

	value = ft_atol(str);
	str_len = ft_strlen(str);
	size = *str == '-' ? str_len - 1 : str_len;
	if (size != ft_nbrlen(value)
	|| value > UINT_MAX
	|| value < INT_MIN)
		lexical_error(p, 1);
	return (value);
}

void		get_value(t_asm *p, t_token *token)
{
	if ((token)->type == REGISTER)
		(token)->value = check_value(p, ft_strchr((token)->str, 'r') + 1);
	else if ((token)->type == INDEX)
		(token)->value = check_value(p, (token)->str);
	else if ((token)->type == DIRECT)
		(token)->value = check_value(p, (token)->str);
}

void		add_token(t_asm *p, t_token **head, t_token *new)
{
	t_token		*tmp;

	get_value(p, new);
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
