# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2022/11/10 18:16:16 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

PRINTF_NAME = libftprintf.a
PRINTF_DIR = ft_printf/

LIBFT_NAME = libft.a
LIBFT_DIR = libft/

SRC = pipex.c\
	  utils.c


OBJ = $(SRC:.c=.o)

${NAME}: ${OBJ}
	$(MAKE) all -C $(PRINTF_DIR)
	$(MAKE) all -C $(LIBFT_DIR)
	$(CC) $(OBJ) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

all: ${NAME}

clean:
		$(MAKE) clean -C $(PRINTF_DIR)
		$(MAKE) clean -C $(LIBFT_DIR)
		${RM} ${OBJ}

fclean: clean
		$(MAKE) fclean -C $(PRINTF_DIR)
		$(MAKE) fclean -C $(LIBFT_DIR)
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re