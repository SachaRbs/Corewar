# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 16:37:43 by crfernan          #+#    #+#              #
#    Updated: 2019/10/28 17:00:39 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_libft.mk
-include ../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
$(error LIBFT_DEPENDANCIES not included)
endif

NAME 	:= $(NAME_LIBFT)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_LIBFT)

OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEPENDANCIES:= $(DEPENDANCIES_LIBFT)

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)


.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_LIBFT)
	@mkdir -p $(OBJ_DIR)
	$(CC) -g3 $(CFLAGS) -o $(OBJ_DIR)/$@ -c $<
	# $(CC) $(OPTI_FLAGS) $(CFLAGS) -o $(OBJ_DIR)/$@ -c $<

-include ./dependancies_$(L_LIBFT_DIR)_object.mk

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

.SILENT: