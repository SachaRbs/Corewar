/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:54:46 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/21 13:33:03 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_aff(t_vm *vm, t_proc *proc)
{
	(void)vm;
	ft_printf("Aff: %c\n", (char)proc->arg_v[0]);
	return (NULL);
}