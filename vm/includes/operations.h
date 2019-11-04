/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:26:45 by crfernan          #+#    #+#             */
/*   Updated: 2019/10/29 14:33:37 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "corewar.h"

typedef struct		s_operations
{
	void	*(*op[16])(t_vm *vm, t_proc *proc);
}					t_operations;

t_operations		*fill_operations(t_vm *vm);

void				*ft_add(t_vm *vm, t_proc *proc);
void				*ft_aff(t_vm *vm, t_proc *proc);
void				*ft_and(t_vm *vm, t_proc *proc);
void				*ft_fork(t_vm *vm, t_proc *proc);
void				*ft_ld(t_vm *vm, t_proc *proc);
void				*ft_ldi(t_vm *vm, t_proc *proc);
void				*ft_lfork(t_vm *vm, t_proc *proc);
void				*ft_live(t_vm *vm, t_proc *proc);
void				*ft_lld(t_vm *vm, t_proc *proc);
void				*ft_lldi(t_vm *vm, t_proc *proc);
void				*ft_or(t_vm *vm, t_proc *proc);
void				*ft_st(t_vm *vm, t_proc *proc);
void				*ft_sti(t_vm *vm, t_proc *proc);
void				*ft_sub(t_vm *vm, t_proc *proc);
void				*ft_xor(t_vm *vm, t_proc *proc);
void				*ft_zjmp(t_vm *vm, t_proc *proc);

#endif
