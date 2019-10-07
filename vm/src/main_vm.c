/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:15:41 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/07 19:10:31 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

/*
***		THE WAY WE'RE FILLING THE MEMORY IS INCORRECT -> CHACK WITH 3 AND 4 CHAMPIONS
*/

int	main(int ac, char **av)
{
	t_vm	*vm;

	if ((vm = ft_memalloc(sizeof(t_vm*))) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	initialize(vm, ac, av);
	run_corewar(vm);
	return (0);
}
