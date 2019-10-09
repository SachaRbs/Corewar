# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:48:47 by ibaran            #+#    #+#              #
#    Updated: 2019/10/09 19:49:42 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_libft_printf.mk
-include ../../../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_PRINTF_DEP),)
$(error LIBFT_PRINTF_DEPENDANCIES not included)
endif

NAME 	:= $(NAME_LIBFT_PRINTF)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_LIBFT_PRINTF)

OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEPENDANCIES:= $(DEPENDANCIES_LIBFT_PRINTF)

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)


.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_LIBFT_PRINTF)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OPTI_FLAGS) $(CFLAGS) -o $(OBJ_DIR)/$@ -c $<

-include ./dependancies_$(L_LIBFT_PRINTF_DIR)_object.mk

$(NAME): $(OBJ)
	ar rc $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ))
	ranlib $(NAME)

debug: OPTI_FLAGS := $(SHARE_DEBUG)
debug: re clean

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
