# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_assembler.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:26:01 by crfernan          #+#    #+#              #
#    Updated: 2019/10/04 18:14:25 by crfernan         ###   ########.fr        #
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

SRC_ASSEMBLER 				=	asm.c \
								header.c \
								init.c \
								instructions.c \
								label.c \
								utils.c

INC_ASSEMBLER					:=	asm.h

DEPENDANCIES_ASSEMBLER_O		:=	Makefile \
								./dependancies_$(L_ASSEMBLER_DIR).mk \
								./dependancies_$(L_ASSEMBLER_DIR)_object.mk

DEPENDANCIES_ASSEMBLER			= $(DEPENDANCIES_ASSEMBLER_O)

INC_ASSEMBLER_EXPORT			:=	$(addprefix $(SHARE_INC_DIR)/,$(INC_ASSEMBLER))
SRC_ASSEMBLER_EXPORT			:=	$(addprefix $(SHARE_SRC_DIR)/,$(SRC_ASSEMBLER))
DEPENDANCIES_ASSEMBLER_E 		:=	$(DEPENDANCIES_ASSEMBLER) $(SRC_ASSEMBLER_EXPORT) $(INC_ASSEMBLER_EXPORT)

DEPENDANCIES_ASSEMBLER_EXPORT	:=	$(addprefix $(L_ASSEMBLER_DIR)/,$(DEPENDANCIES_ASSEMBLER_E))