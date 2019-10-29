# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_vm_object.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:55:40 by crfernan          #+#    #+#              #
#    Updated: 2019/10/29 17:13:49 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

corewar.o: corewar.h error.h
init_vm.o: corewar.h error.h
main_vm.o: corewar.h error.h
utils.o: corewar.h error.h
op.o: corewar.h
error.o: corewar.h error.h

read_mem.o: corewar.h error.h
write_mem.o: corewar.h error.h
print.o: corewar.h error.h

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