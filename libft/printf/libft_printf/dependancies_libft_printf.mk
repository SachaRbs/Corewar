# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_libft_printf.mk                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 19:23:16 by crfernan          #+#    #+#              #
#    Updated: 2019/10/09 19:42:37 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../../../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_LIBFT_PRINTF_DEP				:= 1

L_LIBFT_PRINTF_DIR					:= libft_printf

NAME_LIBFT_PRINTF					:= libft_printf.a

SRC_LIBFT_PRINTF					= \
ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstfold.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
ft_power.c ft_printwordtab.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strsplitlst.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
ft_toupper.c ft_ctoa.c ft_abs.c ft_itoa_base.c ft_strtolower.c ft_ftoa.c \
ft_sumstrstr.c ft_min.c ft_max.c ft_nctoa.c ft_strtoupper.c ft_strndup.c

INC_LIBFT_PRINTF					:=	libft.h

DEPENDANCIES_LIBFT_PRINTF			:=	Makefile \
									./dependancies_$(L_LIBFT_PRINTF_DIR).mk\
									./dependancies_$(L_LIBFT_PRINTF_DIR)_object.mk\
									../../../shared_val.mk
INC_LIBFT_PRINTF_EXPORT				:= $(addprefix $(SHARE_INC_DIR)/,$(INC_LIBFT_PRINTF))
SRC_LIBFT_PRINTF_EXPORT				:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_LIBFT_PRINTF))

DEPENDANCIES_LIBFT_PRINTF_E 		:= $(DEPENDANCIES_LIBFT) $(SRC_LIBFT_EXPORT) $(INC_LIBFT_EXPORT)
DEPENDANCIES_LIBFT_PRINTF_EXPORT	:= $(addprefix $(L_LIBFT_DIR)/,$(DEPENDANCIES_LIBFT_E))
