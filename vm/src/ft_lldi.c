/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:30:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/15 20:31:01 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_lldi(t_vm *vm, t_proc *proc)
{
	int i;

	i = 0;
    (void)vm;
	printf("PLAYER No : %d\n", proc->pnu);
	printf("FUNCTION  : ft_lldi\n");
	printf("action = %s\n", op_tab[proc->action].name);
	while (i < 4)
	{
		printf("arg[%d] = %d\n", i, proc->arg[i]);
		proc->arg[i] = 0;
		i++;
	}
	printf("\n\n");
    return (NULL);
}