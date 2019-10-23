/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:47:17 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/23 14:12:56 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

t_token     *init_token(t_asm *p, t_type type)
{
    t_token *token;

	(void)p;
    if (!(token = malloc(sizeof(t_token))))
        ft_error("TOKEN MALLOC");
    token->content = NULL;
    token->type = type;
    token->y = 0;
    token->x = 0;
    token->next = NULL;
    return (token);
}
