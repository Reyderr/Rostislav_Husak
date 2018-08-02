#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhusak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 16:05:16 by rhusak            #+#    #+#              #
#    Updated: 2018/08/01 18:00:38 by rhusak           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC =		./src/main.c \
			./src/read.c \
		  	./src/map.c \
		  	./src/window.c \
		  	./src/draw.c \
		  	./src/color_fun.c \
		  	./src/keys.c \
		  	./src/picture.c \
		  	./src/rotate.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./libft -lft

CC = gcc

INCLUDES = ./inc

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDES)  $(FLAGSMLX) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
