/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:13:44 by sarobber          #+#    #+#             */
/*   Updated: 2019/11/06 14:52:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../includes/op.h"
# include "../libft/includes/libft.h"
# include <stdio.h>

# define TRUE			1
# define FALSE			0

# define CYCLE_TO_DIE	1536

typedef struct			s_proc
{
	int					alive;
	int					procnum;
	int					pnu;
	int					pc;
	unsigned int		read;
	int					carry;
	int					cycle_live;
	int					live;
	int					cycle;
	unsigned int		action;
	unsigned int		arcode;
	int					arg_v[MAX_ARGS_NUMBER];
	int					arg_t[MAX_ARGS_NUMBER];
	int					arg_a[MAX_ARGS_NUMBER];
	int					reg[REG_NUMBER + 1];
	struct s_proc		*next;
}						t_proc;

typedef struct			s_vm
{
	int					play_free[MAX_PLAYERS + 1];
	unsigned char		mem[MEM_SIZE];
	int					pnum[MAX_PLAYERS + 1];
	char				*names[MAX_PLAYERS];
	long				sizes[MAX_PLAYERS];
	char				*contestants[MAX_PLAYERS + 1];
	int					chmp_alive[MAX_PLAYERS + 1];
	int					cycle_to_die;
	int					next_check;
	int					last_alive;
	int					cpt;
	int					v;
	int					p;
	int					nbr_live;
	int					check;
	int					pct;
	int					procct;
	int					dump;
	int					cycle;
	t_proc				*proc;
}						t_vm;

extern t_op				g_op_tab[17];

/*
***		FROM MAIN
*/

int						initialize(t_vm *vm, int ac, char **av);
void					run_corewar(t_vm *vm);

/*
***		COREWAR HELPERS
*/

int						wrong_ocp(t_proc *proc, t_op op);
int						get_size(t_op op, t_proc *proc, int code, int i);
void					arg_to_zero(t_proc *proc);
void					*check_live(t_vm *vm);
int						get_arg(t_vm *vm, t_proc *proc, t_op op);

/*
***		INIT HELPERS
*/

int						find_procnum(t_vm *vm);
void					set_values_vm(t_vm *vm);
int						find_player_alive(t_vm *vm);
int						find_playernum(t_vm *vm);
void					get_option(t_vm *vm, char **av, int ac, int i);

/*
***		PRINT
*/

void					print_action(t_proc *proc, t_vm *vm, int action_failed);
void					print_memory(unsigned char *mem, t_proc *proc, int d);

/*
***		READ_MEM
*/

unsigned int			big_endian(unsigned int num, int n);
int						read_mem(t_vm *vm, int address, int size);
int						read_mem_and_move_pc(t_vm *vm, int address,
						int size, t_proc *proc);

/*
***		UTILS
*/

int16_t					reverser_16(int16_t a);
int32_t					reverser_32(int32_t a);
int						mod_address(int add);
int						argument(t_vm *vm, t_proc *proc, int arg);
void					pushfront_proc(t_proc **head, t_proc *new);

/*
***		WRITE_MEM
*/

void					writing_mem(t_vm *vm, int pc, int bytes, int value);

#endif
