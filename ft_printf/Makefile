# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2022/11/07 19:16:10 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

SRC = ft_printf.c \
	 ft_parse_chars.c \
	 ft_parse_nums.c \
	 ft_auxiliary.c

OBJ = $(SRC:.c=.o)

${NAME}: ${OBJ}
	${LIB} $@ $^

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

all: ${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
