/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:13:44 by sarobber          #+#    #+#             */
/*   Updated: 2019/10/25 19:31:47 by sarobber         ###   ########.fr       */
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
	int 			procnum;
	int				pnu;
	int				pc;
	unsigned int	read;
	int				carry;
	// int				oc;
	int				cycle_live;
	int				cycle;
	// int				crossed;
	unsigned int	action;
	unsigned int	arcode;
	int				arg_v[MAX_ARGS_NUMBER];
	int				arg_t[MAX_ARGS_NUMBER];
	int				arg_a[MAX_ARGS_NUMBER];
	int				reg[REG_NUMBER + 1];
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
	int				nbr_live;
	int				check;
	int				next_check;
	t_proc			*proc;
}					t_vm;

int					initialize(t_vm *vm, int ac, char **av);
void				run_corewar(t_vm *vm);
// void				check_proc(t_vm *vm, t_proc *current, int pn);
void				pushfront_proc(t_proc **head, t_proc *new);

/*
***		UTILS
*/

extern t_op    g_op_tab[17];

int16_t				reverser_16(int16_t a);
int32_t				reverser_32(int32_t a);
unsigned int		big_endian(unsigned int num, int n);
int					argument(t_vm *vm, t_proc *proc, int arg);
void				writing_mem(t_vm *vm, int pc, int bytes, int value);
int					read_mem(t_vm *vm, int address, int size, int get, t_proc *proc);
int					mod_address(int add);


#endif
