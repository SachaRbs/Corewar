# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_vm_object.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:55:40 by crfernan          #+#    #+#              #
#    Updated: 2019/10/07 15:35:07 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

corewar.o: corewar.h error.h
init_vm.o: corewar.h error.h
main_vm.o: corewar.h error.h
utils.o: corewar.h error.h
op.o: corewar.h
error.o: corewar.h error.h