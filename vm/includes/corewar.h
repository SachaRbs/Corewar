/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:13:44 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/14 18:15:37 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../includes/op.h"
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef int			bool; // What is this for??
# define TRUE			1
# define FALSE			0

# define CYCLE_TO_DIE	1536

typedef struct		s_proc
{
	int				pnu;
	int				pc;
	unsigned int	read;
	int				carry;
	int				oc;
	int				cycle_live;
	int				cycle;
	int				crossed;
	unsigned int	action;
	unsigned int	arcode;
	int				arg[MAX_ARGS_NUMBER];
	int				reg[REG_NUMBER];
	struct s_proc	*next;
}					t_proc;

typedef struct		s_vm
{
	int				play_free[MAX_PLAYERS + 1];
	unsigned char	mem[MEM_SIZE];
	int				pnum[MAX_PLAYERS + 1]; // +1 ou pas ?
	char			*names[MAX_PLAYERS];
	long			sizes[MAX_PLAYERS];
	int				pct;
	int				dump;
	int				live;
	int				cycle;
	int				cycle_to_die;
	int				check;
	int				next_check;
	t_proc			*proc;
}					t_vm;

int					initialize(t_vm *vm, int ac, char **av);
void				run_corewar(t_vm *vm);
unsigned int		get_instruction(t_vm *vm, int size, unsigned int *pc);

#endif
