/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:53:45 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/05 20:26:08 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error.h"

char g_error_message[9][200] = {
	{"# ERROR  1                            ERROR_MALLOC #"},
	{"# ERROR  2    The provided arguments are not valid #"},
	{"# ERROR  3                Please provide champions #"},
	{"# ERROR  4             Failed on read the champion #"},
	{"# ERROR  5                     Nombre magique faux #"},
	{"# ERROR  6            Size du champion trop grande #"},
	{"# ERROR  7                         Mauvaise option #"},
	{"# ERROR  8                       Trop de champions #"},
	{"# ERROR  9   Read procesus from function load_proc #"}
};

void	free_proc(t_vm *vm)
{
	t_proc	*current;
	t_proc	*next;

	if (vm->proc)
	{
		current = vm->proc;
		next = current->next;
		while (next)
		{
			if (current)
				free(current);
			current = next;
			next = current->next;
		}
		if (current)
			free(current);
		current = NULL;
	}
	vm->proc = NULL;
}

/*
***		THIS FUNCTION SHOULD FREE AND SET TO NULL EVERYTHING
*/

void	close_program(t_vm *vm, int out)
{
	int		i;

	i = -1;
	if (vm)
	{
		while (++i < MAX_PLAYERS + 1)
		{
			if (vm->contestants[i])
			{
				free(vm->contestants[i]);
				vm->contestants[i] = NULL;
			}
		}
		free_proc(vm);
		free(vm);
		vm = NULL;
	}
	exit(out);
}

/*
***		THIS FUNCTION PRINTS AN ERROR MESSAGE
***		Previous error message was written like this:
***		write(2, g_error_message[error], ft_strlen(g_error_message[error]));
*/

void	ft_exit(t_vm *vm, t_errors error)
{
	ft_putendl("\e[36m");
	ft_putendl("\n####################################################");
	ft_putendl("####################################################");
	ft_putendl(g_error_message[error]);
	ft_putendl("####################################################");
	ft_putendl("####################################################\n");
	ft_putendl("\e[0m");
	close_program(vm, -1);
}
