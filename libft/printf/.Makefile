# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:48:47 by ibaran            #+#    #+#              #
#    Updated: 2019/02/08 10:55:54 by ibaran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_LIBFT = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
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
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

SRCS_FT_PRINTF = ft_printf_main.c \
for_di.c for_f.c for_uoxx.c for_csppercent.c ft_filling.c \
ft_getting_argument.c ft_importants.c ft_strncpy_zero.c ft_color.c \
ft_argument_value.c ft_dupexit.c
OBJS_FT_PRINTF = $(SRCS_FT_PRINTF:.c=.o)

INCLUDES = ./
FLAGS = -Wall -Wextra -Werror -include ft_printf.h

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc -c $(FLAGS) $(SRCS_FT_PRINTF) -I $(INCLUDES)
	@ar -x ./libft/libft.a
	@ar rc $(NAME) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)
	@ranlib $(NAME)

clean:
	@make -C ./libft/ clean
	@/bin/rm -f $(OBJS_LIBFT) $(OBJS_FT_PRINTF)

fclean: clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME) __.SYMDEF\ SORTED

re: fclean all
