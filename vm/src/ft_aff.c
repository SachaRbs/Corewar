/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:54:46 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 19:59:02 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_aff(t_vm *vm, t_proc *proc)
{
	(void)vm;
	ft_printf("Aff: %c\n", (char)(proc->reg[proc->arg_v[0]] % 256));
	return (NULL);
}
