/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:15:41 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/14 17:59:19 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

/*
***		THE WAY WE'RE FILLING THE MEMORY IS INCORRECT ? -> CHECK WITH 3 AND 4 CHAMPIONS
*/

int	main(int ac, char **av)
{
	t_vm	*vm;
	// (void)ac;
	// (void)av;
//  printf("atoi_base = %d", ft_atoi_base("3ab", 3, 16));
	ft_printf("HELLO EVERYONE\n");
	if ((vm = ft_memalloc(sizeof(t_vm*))) == NULL)
		ft_exit(vm, ERROR_MALLOC);
	initialize(vm, ac, av);
	run_corewar(vm);
	return (0);
}
