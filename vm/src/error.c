/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:53:45 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/07 18:38:42 by crfernan         ###   ########.fr       */
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

void    close_program(t_vm *vm)
{
	/*
        if (mstr)
        {
                if (mstr->start_name)
                        free(mstr->start_name);
                if (mstr->end_name)
                        free(mstr->end_name);
                free_ants(mstr);
                free_nodes(mstr);
                free_pipes(mstr);
                free_moves(mstr);
                free_textures(mstr);
                if (mstr->render)
                        SDL_DestroyRenderer(mstr->render);
                if (mstr->window)
                        SDL_DestroyWindow(mstr->window);
                ft_bzero(mstr, sizeof(t_master));
                free(mstr);
                mstr = NULL;
        }
        IMG_Quit();
        SDL_Quit();
        exit(program_state == VISU_FAILED ? 1 : 0);
	*/
	if (vm)
	{
		free(vm);
		vm = NULL;
	}
	exit (-1);
}

/*
***		THIS FUNCTION PRINTS AN ERROR MESSAGE
*/

void    ft_exit(t_vm *vm, t_errors error)
{
        ft_putendl("\e[36m");
        ft_putendl("\n####################################################");
        ft_putendl("####################################################");
        ft_putendl(g_error_message[error]);
        ft_putendl("####################################################");
        ft_putendl("####################################################\n");
        ft_putendl("\e[0m");
	// write(2, g_error_message[error], ft_strlen(g_error_message[error]));
        close_program(vm);
}
