# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2022/10/13 20:10:46 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

LIBFT_NAME = libft.a
LIBFT_DIR = ./libft

SRC = ft_printf.c \
	 ft_parse_char.c \
	 ft_parse_str.c \
	 ft_parse_ptr.c \
	 ft_parse_int.c \
	 ft_parse_u_int.c \
	 ft_parse_hex.c


OBJ = $(SRC:.c=.o)

${NAME}: ${OBJ}
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp libft/libft.a $(NAME)
	${LIB} $@ $^

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

all: ${NAME}

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		${RM} ${OBJ}

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
