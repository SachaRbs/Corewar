/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/09/05 17:11:02 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void    parsing(t_vm *vm, int ac, char **av)
{
	int i;

	i = 0;
	vm->pnum[vm->pct] = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-' )
		{
			if (av[i][1] == 'n' && !av[i][2] && ac > ++i)
				vm->pnum[vm->pct] = ft_atoi(av[i]); // atoi qui check si le numero de -n 'X' est bon ( < MAX_PLAYERS)
			//else if 'a'/ 'd'
			 //
			else if (write(2, "ERROR mauvaise option\n", 23))
				exit(1);//ERROR
		}
		else if (vm->pct < MAX_PLAYERS)
		{
			vm->names[vm->pct++] = av[i];
			vm->pnum[vm->pct] = -1;
		}
		else if (write(2, "ERROR trop de champions\n", 25))
			exit(1);//ERROR
	}
}

#include <stdio.h>

int     initialize(t_vm *vm, int ac, char **av)
{
	vm->pct = 0;
    if (ac > 1)
        parsing(vm, ac, av);
	else if (write (2 ,"ERROR aucun champions fournis\n", 31))
		exit(1);//ERROR
	check(vm);
	int i = 0;
	return (0);
}