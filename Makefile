# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2022/11/09 17:21:14 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_NAME = libftprintf.a
LIBFT_DIR = ft_printf/

SRC = pipex.c\
	  utils.c	


OBJ = $(SRC:.c=.o)

${NAME}: ${OBJ}
	$(MAKE) all -C $(LIBFT_DIR)
	$(CC) $(OBJ) -lftprintf -L$(LIBFT_DIR) -o $(NAME)

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
