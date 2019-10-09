/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:06:05 by yoribeir          #+#    #+#             */
/*   Updated: 2019/09/27 16:06:05 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

t_token     *init_token(t_asm *p, t_type type)
{
    t_token *token;

    if (!(token = malloc(sizeof(t_token))))
        ft_error("TOKEN MALLOC");
    token->content = NULL;
    token->type = type;
    token->row = 0;
    token->col = 0;
    token->next = NULL;
    return (token);
}
