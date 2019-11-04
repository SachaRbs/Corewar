# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_assembler_object.mk                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 14:36:43 by crfernan          #+#    #+#              #
#    Updated: 2019/11/04 11:56:29 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

asm.o: asm.h
check_token.o: asm.h
check_labels.o: asm.h
error_lexer.o: asm.h
error_parser.o: asm.h
get_ocp.o: asm.h
init.o: asm.h
op.o: asm.h
parse.o: asm.h
parse_header.o: asm.h
parse_instructions.o: asm.h
token.o: asm.h
utils.o: asm.h
free.o: asm.h
write.o: asm.h
encode.o: asm.h