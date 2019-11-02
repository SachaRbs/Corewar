/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:41:53 by epham             #+#    #+#             */
/*   Updated: 2019/11/02 18:01:04 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*write_exec(t_asm *p)
{
	char	*ret;
	int		opcode;
	t_token *token;

	// printf("EXEC SZ = %d\n", p->exec_sz);
	ret = malloc(sizeof(char) * p->exec_sz);
	p->byte_pos = 0;
	token = p->tokens;
	ft_memset(ret, 0, p->exec_sz);
	while (token)
	{
		if (token->type == OP)
		{
			opcode = g_op_tab[token->op_index].opcode;
			write_byte(ret, p->byte_pos, opcode, 1);
			p->byte_pos += 1;
			if (g_op_tab[token->op_index].ocp == 1)
			{
				write_byte(ret, p->byte_pos, 0b11010100, 1);
				p->byte_pos += 1;
			}
		}
		token = token->next;
	}
	return (ret);
}

// void		get_ocp(t_token **token)
// {
// 	int		nb_arg;
// 	int		ret;
// 	t_token	*head;

// 	head = *token;
// 	ret = 0;
// 	nb_arg = g_op_tab[(*token)->op_index].nb_arg;
// 	while (nb_arg)
// 	{
// 		head = head->next;
// 		if (head->type == REGISTER)
// 			ret = 1;
// 		nb_arg--;
// 	}
// }

void		get_exec_sz(t_asm *p)
{
	t_token	*token;
	t_token	*current;

	p->byte_pos = 2192;
	current = NULL;
	token = p->tokens;
	while (token)
	{
		token->byte_pos = p->byte_pos;
		if (token->type == OP)
		{
			current = token;
			token->byte_sz = 1 + g_op_tab[token->op_index].ocp;
			// get_ocp(&token);
		}
		else if (token->type == REGISTER)
			token->byte_sz = 1;
		else if (token->type == INDEX || token->type == IND_LABEL)
			token->byte_sz = 2;
		else if (token->type == DIRECT || token->type == DIRECT_LABEL)
			token->byte_sz = g_op_tab[current->op_index].dir_sz;
		else if (token->type == LABEL)
			token->byte_sz = 0;
		// if (current && token->type != OP)
			// current->byte_sz += token->byte_sz;
		p->byte_pos += token->byte_sz;
		p->exec_sz += token->byte_sz;
		token = token->next;
	}
}
