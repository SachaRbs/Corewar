# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_assembler_object.mk                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 14:36:43 by crfernan          #+#    #+#              #
#    Updated: 2019/10/30 17:37:04 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

asm.o: asm.h
check_token.o: asm.h
check_labels.o: asm.h
error_lexer.o: asm.h
error_parser.o: asm.h
init.o: asm.h
op.o: asm.h
parse.o: asm.h
parse_header.o: asm.h
parse_instructions.o: asm.h
token.o: asm.h
utils.o: asm.h
free.o: asm.h
write.o: asm.h