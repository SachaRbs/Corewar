# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_printf.mk                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 15:26:01 by crfernan          #+#    #+#              #
#    Updated: 2019/10/09 18:29:11 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include libft/dependancies_libft.mk
-include ../../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_PRINTF_DEP			:=	1

L_PRINTF_DIR				:=	printf

NAME_PRINTF					:=	ft_printf

SRC_PRINTF 					=	\
								for_csppercent.c \
								for_di.c \
								for_f.c \
								for_uoxx.c \
								ft_argument_value.c \
								ft_color.c \
								ft_dupexit.c \
								ft_filling.c \
								ft_getting_argument.c \
								ft_importants.c \
								ft_printf_main.c \
								ft_strncpy_zero.c \

INC_PRINTF					:=	ft_printf.h

DEPENDANCIES_PRINTF_O		:=	Makefile \
								./dependancies_$(L_PRINTF_DIR).mk \
								./dependancies_$(L_PRINTF_DIR)_object.mk

DEPENDANCIES_PRINTF			:= $(DEPENDANCIES_PRINTF_O)

INC_PRINTF_EXPORT			:=	$(addprefix $(SHARE_INC_DIR)/,$(INC_PRINTF))
SRC_PRINTF_EXPORT			:=	$(addprefix $(SHARE_SRC_DIR)/,$(SRC_PRINTF))
DEPENDANCIES_PRINTF_E 		:=	$(DEPENDANCIES_PRINTF) $(SRC_PRINTF_EXPORT) $(INC_PRINTF_EXPORT)

DEPENDANCIES_PRINTF_EXPORT	:=	$(addprefix $(L_PRINTF_DIR)/,$(DEPENDANCIES_PRINTF_E))