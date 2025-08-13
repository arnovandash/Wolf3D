# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 11:55:33 by arnovan-          #+#    #+#              #
#    Updated: 2016/06/26 12:08:59 by arnovan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g -O3 -I/opt/homebrew/include -D_THREAD_SAFE -I includes/

SDL_FLAGS=-L/opt/homebrew/lib -lSDL2

RM=rm -f

INC_LIBFT= -L. -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

SRC = main.c get_map.c controls.c \
	  errors.c raycast.c draw.c game.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(SDL_FLAGS)
	@echo "Compilation was successful!"

%.o: $(PATH_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"

fclean: clean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

re: fclean all