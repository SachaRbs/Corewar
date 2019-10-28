/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:26:48 by epham             #+#    #+#             */
/*   Updated: 2019/10/28 16:57:43 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		g_syntactic_tab[40][12] =
{
	{1, 3, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1},
	{-1, 5, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1},
	{5, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1},
	{-1, -1, 10, 7, -1, -1, -1, -1, -1, -1, 6, -1},
	{-1, -1, 10, -1, -1, -1, -1, -1, -1, -1, 6, -1},
	{-1, -1, 10, 7, -1, -1, -1, -1, -1, -1, 8, 40},
	{-1, -1, 10, -1, -1, -1, -1, -1, -1, -1, 8, -1},
	{50},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, 39, 39, -1, -1, -1},
	{-1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1},
	{-1, -1, -1, -1, 39, 39, 39, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 17, 17, 17, 17, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 18, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, 20, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 21, -1, -1},
	{-1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 23, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 26, -1, -1},
	{-1, -1, -1, -1, 27, 27, 27, 27, 27, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, 39, 39, -1, -1, -1},
	{-1, -1, -1, -1, 30, 30, 30, 30, 30, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1},
	{-1, -1, -1, -1, 32, 32, 32, 32, 32, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 33, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, 35, 35, 35, 35, 35, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 36, -1, -1},
	{-1, -1, -1, -1, 37, -1, -1, 37, 37, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 38, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1}
};

void	aff_token(t_asm *env, t_token *token)
{
	if (token->type == OP || token->type == LABEL)
		printf("\n==== NEW INSTRUCTIONS ====\n");
	printf(" ________________________\n");
	printf("|%10s %-12d |\n", "State", env->syntax_state);
	printf("|%10s %-12s |\n", "Type", typestab[token->type]);
	printf("|%10s %-12s |\n", "Value", token->str);
	printf("|%10s %-12d |\n", "Row", token->row);
	printf("|%10s %-12d |\n", "Col", token->col);
	printf("|%10s %-12d |\n", "Op ind", token->op_index);
	printf("|%10s %-12d |\n", "Dir sz", token->dir_sz);
	printf("|________________________|\n");
}

void	print_label_lists(t_asm *env)
{
	t_label *head_labels;
	t_label *head_mentions;

	head_labels = env->labels;
	head_mentions = env->mentions;
	printf("LABELS :\n");
	while (head_labels)
	{
		printf(" [%s]", head_labels->name);
		head_labels = head_labels->next;
	}
	printf("\n\nMENTIONS :\n");
	while (head_mentions)
	{
		printf(" [%s]", head_mentions->name);
		head_mentions = head_mentions->next;
	}
	printf("\n");
}

void	save_label(t_asm *env, t_token *token, int i)
{
	t_label *head;
	t_label *new;

	head = i == 1 ? env->tok_lab : env->mentions;
	printf("SAVING LABEL %s\n", token->str);
	if (!head)
		printf("FIRST LABEL TO BE SAVED\n");
	if (!(new = malloc(sizeof(t_label))))
		return ;
	new->name = ft_strdup(token->str);
	new->col = token->col;
	new->row = token->row;
	new->next = NULL;
	if (!(head))
		head = new;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	print_label_lists(env);
}

int		check_token(t_asm *env)
{
	t_token *token;

	token = env->tokens;
	while (token
	&& env->syntax_state != -1 && env->syntax_state != 40)
	{
		aff_token(env, token);
		env->syntax_state = g_syntactic_tab[env->syntax_state][token->type];
		if (env->syntax_state != -1 && token->type == LABEL)
		{
			save_label(env, token, 1);
			if (!env->tok_lab)
				printf("APPEND LABEL FAILED\n");
		}
		else if (env->syntax_state != -1 && (token->type == IND_LABEL || token->type == DIRECT_LABEL))
		{
			save_label(env, token, 2);
			if (!env->mentions)
				printf("APPEND MENTION FAILED\n");
		}
		if (env->syntax_state == 10)
		{
			if (token->op_index == -1)
			{
				printf("%s:%d:%d: Wrong syntax for operation\n", env->file, token->row, token->col + 1);
				return (0);
			}
			printf("token [%s] going to state %d which correspond to operation [%s]\n", token->str, g_op_tab[token->op_index].syntactic_index, g_op_tab[token->op_index].name);
			env->syntax_state = g_op_tab[token->op_index].syntactic_index;
		}
		token = token->next;
	}
	if (!token)
		env->syntax_state = g_syntactic_tab[env->syntax_state][11];
	if (env->syntax_state == 40)
	{
		print_label_lists(env);
		printf("VALID TOKENS\n");
		return (1);
	}
	else
	{
		printf("INVALID TOKENS at line %d col %d\n", token->row, token->col - 1);
		return (0);
	}
}
