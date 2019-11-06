/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:14:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/06 14:32:00 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

int		find_procnum(t_vm *vm)
{
	int			out;
	t_proc		*current;

	out = 0;
	current = vm->proc;
	while (current)
	{
		if (out <= current->procnum)
			out = current->procnum + 1;
		current = current->next;
	}
	return (out);
}

void	set_values_vm(t_vm *vm)
{
	ft_bzero(vm->play_free, (MAX_PLAYERS + 1) * sizeof(int));
	ft_bzero(vm->pnum, (MAX_PLAYERS + 1) * sizeof(int));
	ft_bzero(vm->sizes, (MAX_PLAYERS + 1) * sizeof(long));
	ft_bzero(vm->names, MAX_PLAYERS);
	ft_bzero(vm->mem, MEM_SIZE * sizeof(unsigned char));
	vm->v = 0;
	vm->p = 0;
	vm->cpt = 1;
	vm->dump = -1;
	vm->pct = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->next_check = vm->cycle_to_die;
	vm->cycle = 0;
	vm->check = 0;
	vm->nbr_live = 0;
}

int		find_player_alive(t_vm *vm)
{
	int			max;
	t_proc		*current;

	current = vm->proc;
	max = -1;
	while (current)
	{
		if (current->pnu > max)
			max = current->pnu;
		current = current->next;
	}
	return (max);
}

int		find_playernum(t_vm *vm)
{
	int		i;
	int		min;

	i = 0;
	min = 20;
	while (i++ < MAX_PLAYERS)
		if (min > i && vm->play_free[i] == 0)
			min = i;
	vm->play_free[min] = 1;
	return (min);
}

void	get_option(t_vm *vm, char **av, int ac, int i)
{
	if (av[i][1] == 'n' && !av[i][2] && ac > ++i)
	{
		vm->pnum[vm->pct] = ft_atoi(av[i]);
		if (vm->pnum[vm->pct] > MAX_PLAYERS || vm->pnum[vm->pct] < 1)
			ft_exit(vm, INVALID_INPUT);
		vm->play_free[vm->pnum[vm->pct]] = 1;
	}
	else if (av[i][1] == 'd' && !av[i][2] && ac > ++i)
	{
		if ((vm->dump = ft_atoi(av[i])) < 0)
			ft_exit(vm, INVALID_INPUT);
	}
	else if (av[i][1] == 'v' && !av[i][2] && ac > ++i)
	{
		if ((vm->v = ft_atoi(av[i])) < 0 || vm->v > 3)
			ft_exit(vm, INVALID_INPUT);
	}
	else if (av[i][1] == 'p' && !av[i][2] && ac > i + 1)
		vm->p = 1;
	else
		ft_exit(vm, MAUVAISE_OPTION);
}
