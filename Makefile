# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2023/01/23 20:14:56 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_NAME = libft.a
LIBFT_DIR = lib/libft/

SRC_DIR = src/
_SRC =	main.c\
		errors.c\
		utils.c\
		parser.c\
		init.c\
		childs.c\
		exit.c\

SRC = $(addprefix $(SRC_DIR), $(_SRC))

OBJ = $(SRC:.c=.o)

${NAME}: ${OBJ}
	$(MAKE) all -C $(LIBFT_DIR)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

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
