# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:21:03 by franmart          #+#    #+#              #
#    Updated: 2023/10/01 18:35:11 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus

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
		exit.c

INCLUDES = -I ./inc -I ./lib/libft/include

BONUS_DIR = bonus/
_BONUS =	main_bonus.c\
			errors_bonus.c\
			utils_bonus.c\
			parser_bonus.c\
			init_bonus.c\
			childs_bonus.c\
			exit_bonus.c

SRC = $(addprefix $(SRC_DIR), $(_SRC))
OBJ = $(SRC:.c=.o)

BONUS_SRC = $(addprefix $(BONUS_DIR), $(_BONUS))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

${NAME}: ${OBJ}
	@$(MAKE) all -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	@git submodule update --init --recursive
	${CC} ${FLAGS} ${INCLUDES} -c $^ -o $@

all: ${NAME}

${BONUS_NAME}: ${BONUS_OBJ}
	@$(MAKE) all -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

bonus: ${BONUS_NAME}

clean:
		@$(MAKE) clean -C $(LIBFT_DIR)
		${RM} ${OBJ}
		${RM} ${BONUS_OBJ}

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_DIR)
		${RM} ${NAME}
		${RM} ${BONUS_NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
