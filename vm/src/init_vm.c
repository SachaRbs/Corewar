/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:56:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/15 19:03:50 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

void	parsing(t_vm *vm, int ac, char **av, int i)
{
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'n' && !av[i][2] && ac > ++i)
			{
				if ((vm->pnum[vm->pct] = ft_atoi(av[i])) > MAX_PLAYERS)
					ft_exit(vm, INVALID_INPUT);
				vm->play_free[vm->pnum[vm->pct]] = 1;
			}
			else if (av[i][1] == 'd')
				vm->dump = ft_atoi(av[i]);
			else
				ft_exit(vm, MAUVAISE_OPTION);
		}
		else if (vm->pct < MAX_PLAYERS)
		{
			vm->names[vm->pct] = av[i];
			if (!vm->pnum[vm->pct])
				vm->pnum[vm->pct] = -1;
			vm->pct++;
		}
		else
			ft_exit(vm, TROP_DE_CHAMPS);
	}
}

void	set_to_zero(t_vm *vm)
{
	ft_bzero(vm->play_free, (MAX_PLAYERS + 1) * sizeof(int));
	ft_bzero(vm->pnum, (MAX_PLAYERS + 1) * sizeof(int));
	ft_bzero(vm->sizes, (MAX_PLAYERS + 1) * sizeof(long));
	ft_bzero(vm->names, MAX_PLAYERS); // * sizeof(something)
	ft_bzero(vm->mem, MEM_SIZE * sizeof(unsigned char));
	vm->dump = -1;
	vm->pct = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle = 0;
	vm->check = 0;
}

void	initialize(t_vm *vm, int ac, char **av)
{
	int		i;
	t_proc	*proc;

	i = -1;
	set_to_zero(vm);
	if (ac > 1)
		parsing(vm, ac, av, 0);
	else
		ft_exit(vm, INVALID_INPUT);
	if (!vm->pct)
		ft_exit(vm, NO_CHAMPIONS);
	ft_putendl("Introducing contestants...");
	while (++i < vm->pct)
	{
		if ((proc = ft_memalloc(sizeof(t_proc))) == NULL)
			ft_exit(vm, ERROR_MALLOC);
		check_proc(vm, proc, i);
	}
	print_memory(vm->mem);
}
