# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_assembler.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:26:01 by crfernan          #+#    #+#              #
#    Updated: 2019/11/04 11:57:27 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_ASSEMBLER_DEP			:=	1

L_ASSEMBLER_DIR				:=	assembler

NAME_ASSEMBLER				:=	asm

SRC_ASSEMBLER 				=	asm.c					\
								check_token.c			\
								check_labels.c			\
								encode.c				\
								error_lexer.c			\
								error_parser.c			\
								free.c					\
								init.c					\
								get_ocp.c				\
								op.c					\
								parse.c					\
								parse_header.c			\
								parse_instructions.c	\
								token.c					\
								utils.c					\
								write.c					\

INC_ASSEMBLER					:=	asm.h

DEPENDANCIES_ASSEMBLER_O		:=	Makefile \
								./dependancies_$(L_ASSEMBLER_DIR).mk \
								./dependancies_$(L_ASSEMBLER_DIR)_object.mk

DEPENDANCIES_ASSEMBLER			= $(DEPENDANCIES_ASSEMBLER_O)

INC_ASSEMBLER_EXPORT			:=	$(addprefix $(SHARE_INC_DIR)/,$(INC_ASSEMBLER))
SRC_ASSEMBLER_EXPORT			:=	$(addprefix $(SHARE_SRC_DIR)/,$(SRC_ASSEMBLER))
DEPENDANCIES_ASSEMBLER_E 		:=	$(DEPENDANCIES_ASSEMBLER) $(SRC_ASSEMBLER_EXPORT) $(INC_ASSEMBLER_EXPORT)

DEPENDANCIES_ASSEMBLER_EXPORT	:=	$(addprefix $(L_ASSEMBLER_DIR)/,$(DEPENDANCIES_ASSEMBLER_E))