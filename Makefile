# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 11:55:33 by arnovan-          #+#    #+#              #
#    Updated: 2016/06/23 16:04:15 by antricht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

LINUX=-I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx

MAC=-L/usr/lib -lmlx -framework OpenGL -framework AppKit

RM=rm -f

INC_LIBFT= -L. -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

PATH_HD= -I includes/

SRC = $(PATH_SRC)main.c $(PATH_SRC)get_map.c $(PATH_SRC)controls.c \
	  $(PATH_SRC)errors.c $(PATH_SRC)raycast.c

OBJ = main.o get_map.o controls.o errors.o raycast.o

$(NAME):
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(MAC)
	@echo "Compilation was successful!"

all: $(NAME)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(LINUX)
	@echo "Compilation was successful!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"

fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

re: fclean all
