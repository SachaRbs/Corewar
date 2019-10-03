# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_vm.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:26:01 by crfernan          #+#    #+#              #
#    Updated: 2019/10/03 16:08:22 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_COREWAR_DEP := 1

L_COREWAR_DIR	:= vm

NAME_COREWAR	:= corewar

SRC_COREWAR =  \
	corewar.c\
	init_vm.c\
	main_vm.c\
	utils.c\
	op.c

INC_COREWAR					:= corewar.h \
							libft/libft.h

INC_OP_H					:= op.h

DEPENDANCIES_COREWAR_O		:= Makefile ./dependancies_$(L_COREWAR_DIR).mk\
								 ./dependancies_$(L_COREWAR_DIR)_object.mk\
								 ../shared_val.mk #./includes/error.h

DEPENDANCIES_COREWAR			:= $(DEPENDANCIES_COREWAR_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_COREWAR_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_COREWAR))
SRC_COREWAR_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_COREWAR))
DEPENDANCIES_COREWAR_E 		:= $(DEPENDANCIES_COREWAR) $(SRC_COREWAR_EXPORT) $(INC_COREWAR_EXPORT)
DEPENDANCIES_COREWAR_EXPORT	:= $(addprefix $(L_COREWAR_DIR)/,$(DEPENDANCIES_COREWAR_E))
DEPENDANCIES_COREWAR_EXPORT	+= $(addprefix $(SHARE_INC_DIR)/,$(INC_OP_H))