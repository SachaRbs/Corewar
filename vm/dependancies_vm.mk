# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_vm.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:26:01 by crfernan          #+#    #+#              #
#    Updated: 2019/11/06 14:46:32 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_COREWAR_DEP			:=	1

L_COREWAR_DIR				:=	vm

NAME_COREWAR				:=	corewar

SRC_COREWAR 				=	corewar.c \
								corewar_helpers.c \
								error.c \
								ft_add.c \
								ft_aff.c \
								ft_and.c \
								ft_fork.c \
								ft_ld.c \
								ft_ldi.c \
								ft_lfork.c \
								ft_live.c \
								ft_lld.c \
								ft_lldi.c \
								ft_or.c \
								ft_st.c \
								ft_sti.c \
								ft_sub.c \
								ft_xor.c \
								ft_zjmp.c \
								init_helpers.c \
								init_vm.c \
								main_vm.c \
								op.c \
								operations.c \
								print.c \
								read_mem.c \
								utils.c \
								write_mem.c

INC_COREWAR					:=	corewar.h \
								error.h \
								operations.h

DEPENDANCIES_COREWAR_O		:=	Makefile \
								./dependancies_$(L_COREWAR_DIR).mk \
								./dependancies_$(L_COREWAR_DIR)_object.mk

DEPENDANCIES_COREWAR		:= $(DEPENDANCIES_COREWAR_O)

INC_COREWAR_EXPORT			:=	$(addprefix $(SHARE_INC_DIR)/,$(INC_COREWAR))
SRC_COREWAR_EXPORT			:=	$(addprefix $(SHARE_SRC_DIR)/,$(SRC_COREWAR))
DEPENDANCIES_COREWAR_E 		:=	$(DEPENDANCIES_COREWAR) $(SRC_COREWAR_EXPORT) $(INC_COREWAR_EXPORT)

DEPENDANCIES_COREWAR_EXPORT	:=	$(addprefix $(L_COREWAR_DIR)/,$(DEPENDANCIES_COREWAR_E))