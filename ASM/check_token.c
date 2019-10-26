/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:26:48 by epham             #+#    #+#             */
/*   Updated: 2019/10/26 17:29:53 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

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
	{-1, -1, -1, -1, -1, 39, 39, 39, 39, -1, -1, -1},
	{-1, -1, -1, -1, 30, 30, 30, 30, 30, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1},
	{-1, -1, -1, -1, 32, 32, 32, 32, 32, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 33, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, 35, 35, 35, 35, 35, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 36, -1, -1},
	{-1, -1, -1, -1, -1, 37, 37, 37, 37, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 38, -1, -1},
	{-1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1}
};

// void	get_op(t_asm *env, t_token *token)
// {
	// if (!ft_strcmp(token->str, "aff"))
	// 	env->syntax_state = 11;
	// else if (!ft_strcmp(token->str, "live") || !ft_strcmp(token->str, "zjmp")
	// || !ft_strcmp(token->str, "fork") || !ft_strcmp(token->str, "lfork"))
	// 	env->syntax_state = 12;
	// else if (!ft_strcmp(token->str, "st"))
	// 	env->syntax_state = 13;
	// else if (!ft_strcmp(token->str, "ld") || !ft_strcmp(token->str, "lld"))
	// 	env->syntax_state = 16;
	// else if (!ft_strcmp(token->str, "add") || !ft_strcmp(token->str, "sub"))
	// 	env->syntax_state = 19;
	// else if (!ft_strcmp(token->str, "sti"))
	// 	env->syntax_state = 24;
	// else if (!ft_strcmp(token->str, "and") || !ft_strcmp(token->str, "or")
	// || !ft_strcmp(token->str, "xor"))
	// 	env->syntax_state = 29;
	// else if (!ft_strcmp(token->str, "ldi") || !ft_strcmp(token->str, "lldi"))
	// 	env->syntax_state = 34;
	// else
	// 	return (-1);
// }

// void	get_bytepos(t_asm *env, t_token *token)
// {
	
// }

void	aff_token(t_asm *env, t_token *token)
{
	if (token->type == OP || token->type == LABEL)
		printf("\n============== NEW INSTRUCTIONS ==============\n");
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

int		check_token(t_asm *env)
{
	t_token *token;

	token = env->tokens;
	while (token
	&& (env->syntax_state != -1 && env->syntax_state != 40))
	{
		aff_token(env, token);
		env->syntax_state = g_syntactic_tab[env->syntax_state][token->type];
		if (env->syntax_state == 10)
			env->syntax_state = g_op_tab[token->op_index].syntactic_index;
		// get_bytepos(env, token);
		token = token->next;
	}
	if (!token)
		env->syntax_state = g_syntactic_tab[env->syntax_state][11];
	if (env->syntax_state == 40)
	{
		printf("VALID TOKENS\n");
		return (1);
	}
	else
	{
		printf("INVALID TOKENS at line %d col %d\n", token->row, token->col);
		return (0);
	}
}
