# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_vm_object.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:55:40 by crfernan          #+#    #+#              #
#    Updated: 2019/10/16 15:01:05 by sarobber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

corewar.o: corewar.h error.h
init_vm.o: corewar.h error.h
init_proc.o: corewar.h error.h
main_vm.o: corewar.h error.h
utils.o: corewar.h error.h
op.o: corewar.h
error.o: corewar.h error.h
operations.o: operations.h error.h
ft_add.o: operations.h error.h
ft_aff.o: operations.h error.h
ft_and.o: operations.h error.h
ft_fork.o: operations.h error.h
ft_ld.o: operations.h error.h
ft_ldi.o: operations.h error.h
ft_lfork.o: operations.h error.h
ft_live.o: operations.h error.h
ft_lld.o: operations.h error.h
ft_lldi.o: operations.h error.h
ft_or.o: operations.h error.h
ft_st.o: operations.h error.h
ft_sti.o: operations.h error.h
ft_sub.o: operations.h error.h
ft_xor.o: operations.h error.h
ft_zjmp.o: operations.h error.h