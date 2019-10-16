/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:15:41 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/16 17:12:19 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

int	main(int ac, char **av)
{
	t_vm	*vm;

	if ((vm = (t_vm*)ft_memalloc(sizeof(t_vm))) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	initialize(vm, ac, av);
	run_corewar(vm);
	return (0);
}

/*
***	Posible idea of why everything is fucked up
*/

	// if ((vm = (t_vm*)ft_memalloc(sizeof(t_vm))) == NULL)
	// 	ft_exit(vm, ERROR_MALLOC);
