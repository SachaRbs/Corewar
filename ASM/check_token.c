/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:26:48 by epham             #+#    #+#             */
/*   Updated: 2019/11/01 17:30:07 by yoribeir         ###   ########.fr       */
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
	{-1, -1, 10, 9, -1, -1, -1, -1, -1, -1, 8, 40},
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

void	fill_optoken(t_token *token)
{
	token->op_index = is_instruction(token->str);
	token->dir_sz = g_op_tab[token->op_index].dir_sz;
}

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

int		check_end_syntax(t_asm *env, t_token *token)
{
	t_label	*label;

	label = NULL;
	// EOF
	if (!token)
		env->syntax_state = g_syntactic_tab[env->syntax_state][11];
	if (env->syntax_state == 40 && !token)
	{
		if ((label = check_labels(env)))
			return (get_error(env, label->from));
		else
		{
			printf(GRN"PARSING OK\n"RESET);
			return (0);
		}
	}
	else
		return (get_error(env, token));
}

int		check_token(t_asm *env)
{
	t_token	*token;
	t_label	*label_check;

	token = env->tokens;
	label_check = NULL;
	while (token
	&& env->syntax_state != -1 && env->syntax_state != 40)
	{
		// aff_token(env, token);
		env->syntax_state = g_syntactic_tab[env->syntax_state][token->type];
		if (env->syntax_state == 5)
			env->f_header = 1;
		if (env->syntax_state == -1)
			return(get_error(env, token));
		else if (token->type == LABEL)
			save_label(&env->labels, token);
		else if ((token->type == IND_LABEL || token->type == DIRECT_LABEL))
			save_label(&env->mentions, token);
		if (env->syntax_state == 10)
		{
			if (token->op_index == -1)
				return (get_error(env, token));
			printf("token [%s] going to state %d = operation [%s]\n", token->str, g_op_tab[token->op_index].syntactic_index, g_op_tab[token->op_index].name);
			env->syntax_state = g_op_tab[token->op_index].syntactic_index;
		}
		token = token->next;
	}
	return (check_end_syntax(env, token));
}
