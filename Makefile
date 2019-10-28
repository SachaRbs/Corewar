# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 12:51:56 by crfernan          #+#    #+#              #
#    Updated: 2019/10/28 17:00:06 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./libft/dependancies_libft.mk
include ./vm/dependancies_vm.mk
include ./assembler/dependancies_assembler.mk
include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
	$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
	$(error LIBFT_DEPENDANCIES not included)
endif
ifeq ($(CHECK_COREWAR_DEP),)
	$(error COREWAR_DEPENDANCIES not included)
endif
ifeq ($(CHECK_ASSEMBLER_DEP),)
	$(error ASSEMBLER_DEPENDANCIES not included)
endif

NAME := $(NAME_COREWAR) $(NAME_ASSEMBLER)

C_NAME = "NAME_COREWAR=../$(NAME_COREWAR)"
A_NAME = "NAME_ASSEMBLER=../$(NAME_ASSEMBLER)"

.PHONY: all clean fclean re debug

all : $(NAME)

STD_DEPENDANCY := $(DEPENDANCIES_LIBFT_EXPORT)

$(NAME_COREWAR) : $(DEPENDANCIES_COREWAR_EXPORT) $(STD_DEPENDANCY)
	$(MAKE) -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) -C $(L_COREWAR_DIR) $(C_NAME) --no-print-directory

$(NAME_ASSEMBLER) : $(DEPENDANCIES_ASSEMBLER_EXPORT) $(STD_DEPENDANCY)
	$(MAKE) -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE)  -C $(L_ASSEMBLER_DIR) $(A_NAME) --no-print-directory

clean:
	$(MAKE) clean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) clean -C $(L_COREWAR_DIR) --no-print-directory
	$(MAKE) clean -C $(L_ASSEMBLER_DIR) --no-print-directory

fclean:
	$(MAKE) fclean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_COREWAR_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_ASSEMBLER_DIR) --no-print-directory
	rm -f $(NAME)

debug:
	$(MAKE) debug -C $(L_COREWAR_DIR) $(C_NAME) --no-print-directory
	$(MAKE) debug -C $(L_ASSEMBLER_DIR) $(A_NAME) --no-print-directory

re: fclean all
.SILENT: