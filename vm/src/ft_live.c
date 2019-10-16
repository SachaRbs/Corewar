/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:55:09 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/16 15:05:57 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "error.h"
#include "op.h"

void	*ft_live(t_vm *vm, t_proc *proc)
{
	int i;

	i = 0;
    (void)vm;
	printf("PLAYER No %d :\n", proc->pnu);
	printf("FUNCTION	 : ft_live\n");
	printf("action = %s\n", op_tab[proc->action].name);
	while (i < 4)
	{
		printf("arg_v[%d] = %d\n", i, proc->arg_v[i]);
		proc->arg_v[i] = 0;
		i++;
	}
	printf("\n\n");
    return (NULL);
}