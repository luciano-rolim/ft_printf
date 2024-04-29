# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeneghe <lmeneghe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:57:38 by lmeneghe          #+#    #+#              #
#    Updated: 2024/04/26 16:04:59 by lmeneghe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CFILES = ft_printf.c num_functions.c

OFILES = $(CFILES:%.c=%.o)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re
