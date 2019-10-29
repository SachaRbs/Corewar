# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:05:01 by anonymous         #+#    #+#              #
#    Updated: 2019/09/17 17:11:09 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm
INCLUDES	=	includes
LIBS		=	libft
LIB			=	ft
# FLAGS = -Wall -Werror -Wextra
<<<<<<< HEAD
SRCS		=	asm.c			\
				utils.c			\
				init.c			\
				parse.c			\
				token.c			\
				op.c			\
				check_token.c \
				parse_instructions.c \
				parse_header.c \
				parse_label.c \
=======
SRCS		=	asm.c					\
				utils.c					\
				init.c					\
				parse_instructions.c	\
				parse_header.c			\
				parse_label.c			\
				parse.c					\
				token.c					\
				op.c					\
				check_token.c			\
				error_token.c
>>>>>>> fb41fec954d9d5b1b3d496978a6f50e7d5f8c1d8
# SRCSREP = srcs
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I$(INCLUDES) -c $^

$(NAME): $(OBJS)
	@make -C libft
	gcc $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all