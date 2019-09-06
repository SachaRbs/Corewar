/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:13:44 by sarobber          #+#    #+#             */
/*   Updated: 2019/09/06 16:11:11 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "../libft/libft.h"


typedef struct		s_proc
{
	int				pnu;
	int				pc;
	int				carry;
	// t_reg			registre[REG_NUMBER];
	struct s_proc			*next;
}					t_proc;

typedef struct		s_vm
{
	unsigned char	mem[MEM_SIZE];
	int				pnum[MAX_PLAYERS + 1]; // +1 ou pas ?
	char			*names[MAX_PLAYERS];
	long			sizes[MAX_PLAYERS];
	int				pct;
	t_proc			*proc;
}             		t_vm;

int     initialize(t_vm *vm, int ac, char **av);