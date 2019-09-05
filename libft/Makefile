NAME= libft.a
SRC_NAME=\
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
		ft_lstmap.c   \
		get_next_line.c

OBJ= $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -g -c $(SRC_NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mYour lib is ready\033[0m"
clean:
	@rm -rf $(OBJ)
	@echo "\033[41mFile .o are removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[41m$(NAME) is deleted\033[0m"

re: fclean all
