# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:47:33 by gkganakg          #+#    #+#              #
#    Updated: 2018/10/15 17:27:41 by gkganakg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = minishell

LIBFT_PATH = libft/

SRC = main.c\
	about_env.c\
	check_commands.c\
	set_env.c\
	unset_env.c\
	cd_funct.c\
	search_str.c\
	saver.c\
	exec.c\
	exec_help.c

	

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc -o $(NAME) $(FLAGS) $(SRC)  libft/libft.a
	@echo "objects created"
	@echo "mishilell exe created"

clean:
	@make -C $(LIBFT_PATH) / clean
	@rm -f $(OBJ)
	@echo "objects cleaned"

fclean: clean
	@rm -f  $(NAME)
	@echo "objects and library cleaned"

re: fclean all

.PHONY: all, clean, fclean, re
