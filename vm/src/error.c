/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:53:45 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/08 15:32:45 by crfernan         ###   ########.fr       */
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
	{"# ERROR  8   Read procesus from function load_proc #"}
};

/*
***		THIS FUNCTION SHOULD FREE AND SET TO NULL EVERYTHING
*/

void	close_program(t_vm *vm)
{
	if (vm)
	{
		free(vm);
		vm = NULL;
	}
	exit(-1);
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
	close_program(vm);
}
