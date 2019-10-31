# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_libft.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 16:39:55 by crfernan          #+#    #+#              #
#    Updated: 2019/10/31 17:54:27 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./shared_val.mk
-include ../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_LIBFT_DEP := 1

L_LIBFT_DIR	:= libft

NAME_LIBFT	:= libft.a

SRC_LIBFT = \
	ft_strjoin.c \
	ft_memalloc.c \
	ft_strcat.c \
	ft_strcpy.c \
	ft_memset.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strncat.c \
	ft_strdup.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memdel.c \
	ft_strdel.c \
	ft_memcmp.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_putnbr.c \
	ft_putendl.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
	ft_strsub.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstnew.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \
	ft_itoa_base.c \
	ft_atoi_base.c \
	ft_ctoa.c \
	ft_nctoa.c \
	ft_ftoa.c \
	ft_itoa_printf.c \
	ft_strchr_printf.c \
	ft_strcmp_printf.c \
	ft_strlen_printf.c \
	ft_strtolower_printf.c \
	ft_atoi_printf.c \
	ft_max.c \
	ft_min.c \
	ft_power.c \
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
	ft_strncpy_zero.c \
	ft_printf_main.c \
	ft_strnjoin.c \
	ft_strndup.c \
	ft_islower.c \
	ft_atol.c \

INC_LIBFT					:=	libft.h \
								ft_printf.h

DEPENDANCIES_LIBFT			:=	Makefile \
								./dependancies_$(L_LIBFT_DIR).mk\
								./dependancies_$(L_LIBFT_DIR)_object.mk\
								../shared_val.mk

INC_LIBFT_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_LIBFT))
SRC_LIBFT_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_LIBFT))

DEPENDANCIES_LIBFT_E 		:= $(DEPENDANCIES_LIBFT) $(SRC_LIBFT_EXPORT) $(INC_LIBFT_EXPORT)
DEPENDANCIES_LIBFT_EXPORT	:= $(addprefix $(L_LIBFT_DIR)/,$(DEPENDANCIES_LIBFT_E))
