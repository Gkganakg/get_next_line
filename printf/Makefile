# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 12:02:20 by gkganakg          #+#    #+#              #
#    Updated: 2018/08/13 15:43:42 by gkganakg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  ft_strcpy.c \
	  ft_strchr.c \
	  ft_strncpy.c \
	  ft_strnew.c \
	  ft_strncpy.c \
	  ft_strndup.c\
	  ft_strdup.c \
	  ft_putchar.c \
	  ft_putnchar.c \
	  parse_str.c \
	  verify_flags.c\
	  ft_strpbrk.c \
	  ft_bzero.c \
	  ft_strlen.c \
	  ft_strcmp.c \
	  ft_atoi.c \
	  ft_width.c \
	  ft_precision.c \
	  ft_sort_types.c \
	  ft_print_lld.c \
	  ft_print_flags.c \
	  ft_putstr.c \
	  padding.c \
	  ft_print_u_hex.c \
      ft_hex_len.c \
	  ft_llu_len.c \
	  ft_print_oll.c \
	  ft_len_base.c \
	  ft_put_llu_base.c \
	  ft_hex_len.c \
	  ft_u_len_base.c \
	  ft_put_u_longlong_base.c\
	  ft_print_llx.c \
	   deal_conversions.c \
	   print_ptr.c \
	   ft_deal_chrstr.c \
	 	ft_deal_unicodes.c \
	   ft_unilen.c \
	   ft_print_uni.c \
	   ft_strsplit.c \
	   ft_atoi_base.c \
	   ft_itoa_longlong_base.c \
	   ft_memdel.c \
	   ft_skip_whitespace.c \
	   ft_strsub.c \
	   ft_itoa.c \
	   ft_strjoin.c \
	   ft_lenll.c \
	   ft_print_ull.c \
	   ft_strdel.c \
	   ft_put_longlong_base.c \
	   ft_memset.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Objects Created"
	@ranlib $(NAME)
	@echo "Libftprintf.a created"

clean : 
	@rm -f $(OBJ)
	@echo "Objects cleaned"

fclean : clean
	@rm -f $(NAME)
	@echo "objects cleaned then ...\
		Libftprintf.a cleaned"

re : fclean all

.PHONY: all, clean, fclean, re




