# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_vm_object.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:55:40 by crfernan          #+#    #+#              #
#    Updated: 2019/10/03 16:10:58 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

corewar.o: corewar.h
init_vm.o: corewar.h libft/libft.h
main_vm.o: corewar.h
utils.o: corewar.h
op.o: ../includes/op.h