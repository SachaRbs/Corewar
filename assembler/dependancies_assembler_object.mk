# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_assembler_object.mk                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 14:36:43 by crfernan          #+#    #+#              #
#    Updated: 2019/10/28 16:40:25 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

asm.o: asm.h
check_token.o: asm.h
error_token.o: asm.h
init.o: asm.h
op.o: asm.h
parse.o: asm.h
parse_header.o: asm.h
parse_instructions.o: asm.h
parse_label.o: asm.h
token.o: asm.h
utils.o: asm.h
write.o: asm.h