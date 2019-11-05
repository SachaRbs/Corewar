# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    shared_val.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:20:56 by crfernan          #+#    #+#              #
#    Updated: 2019/11/05 12:05:54 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_SHARED_VAL		:= 1

SHARE_SRC_DIR			:= src
SHARE_OBJ_DIR			:= obj
SHARE_INC_DIR			:= includes

vpath %.c $(SHARE_SRC_DIR)
vpath %.h $(SHARE_INC_DIR)
vpath %.o $(SHARE_OBJ_DIR)

SHARE_FLAGS				:=	-Wall -Wextra -Werror
# OPTI_FLAGS				:=	
OPTI_FLAGS				:=	-O3 -ffreestanding -fno-builtin -flto
SHARE_FLAGS				+=	-I $(SHARE_INC_DIR) \
							-I $(addprefix ../,$(SHARE_INC_DIR)) \
							-I $(addprefix ../libft/,$(SHARE_INC_DIR))
SHARE_DEBUG				:=	-g3