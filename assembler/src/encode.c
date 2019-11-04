/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:41:53 by epham             #+#    #+#             */
/*   Updated: 2019/11/04 17:27:24 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*write_header(t_asm *p)
{
	char	*ret;

	ret = malloc(sizeof(char) * SIZE);
	ft_memset(ret, 0, SIZE);
	p->byte_pos = 0;
	write_byte(ret, p->byte_pos, COREWAR_EXEC_MAGIC, 4);
	p->byte_pos += 4;
	ft_memcpy(&ret[p->byte_pos], p->champ, ft_strlen(p->champ));
	p->byte_pos += PROG_NAME_LENGTH + 4;
	write_byte(ret, p->byte_pos, p->exec_sz, 4);
	p->byte_pos += 4;
	ft_memcpy(&ret[p->byte_pos], p->comment, ft_strlen(p->comment));
	p->byte_pos += COMMENT_LENGTH + 4;
	return (ret);
}

char		*write_exec(t_asm *p)
{
	char	*ret;
	t_token *token;

	ret = malloc(sizeof(char) * p->exec_sz);
	p->byte_pos = 0;
	token = p->tokens;
	ft_memset(ret, 0, p->exec_sz);
	while (token)
	{
		if (token->type == OP)
		{
			write_byte(ret, p->byte_pos, g_op_tab[token->op_index].opcode, 1);
			if (g_op_tab[token->op_index].ocp == 1)
				write_byte(ret, p->byte_pos + 1, token->ocp, 1);
		}
		else if (token->type == REGISTER
		|| token->type == DIRECT || token->type == INDEX)
			write_byte(ret, p->byte_pos, token->value, token->byte_sz);
		else if (token->type == IND_LABEL || token->type == DIRECT_LABEL)
			write_byte(ret, p->byte_pos, token->value, token->byte_sz);
		p->byte_pos += token->byte_sz;
		token = token->next;
	}
	return (ret);
}

void		get_byte_sz(t_asm *p, t_token **token, t_token **current, int *pos)
{
	if ((*token)->type == OP)
	{
		*pos = p->byte_pos;
		*current = *token;
		(*token)->byte_sz = 1 + g_op_tab[(*token)->op_index].ocp;
		get_ocp(token);
	}
	else if ((*token)->type == REGISTER)
		(*token)->byte_sz = 1;
	else if ((*token)->type == INDEX || (*token)->type == IND_LABEL)
		(*token)->byte_sz = 2;
	else if ((*token)->type == DIRECT || (*token)->type == DIRECT_LABEL)
		(*token)->byte_sz = g_op_tab[(*current)->op_index].dir_sz;
	else if ((*token)->type == LABEL)
		(*token)->byte_sz = 0;
}

void		get_exec_sz(t_asm *p)
{
	t_token	*token;
	t_token	*current;
	int		byte_pos;

	p->byte_pos = 2192;
	byte_pos = p->byte_pos;
	current = NULL;
	token = p->tokens;
	while (token)
	{
		token->byte_pos = p->byte_pos;
		get_byte_sz(p, &token, &current, &byte_pos);
		if (token->type == DIRECT_LABEL || token->type == IND_LABEL)
			token->byte_pos = byte_pos;
		p->byte_pos += token->byte_sz;
		p->exec_sz += token->byte_sz;
		token = token->next;
	}
}
