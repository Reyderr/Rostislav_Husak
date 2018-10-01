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

AT = \033[37;1;41m Attantion!!! \033[0m

NAME = wolf3d

SRC =		./src/main.c \
		./src/window.c \
		./src/draw.c \
		./src/keys.c \
		./src/reading.c\
		./src/read.c \
		./src/calculation.c\
		./src/command.c \
		./src/texture.c \
		./src/wall.c \
		./src/draw_calc.c \
		./src/key_move.c \
		./src/chck.c \
		./src/r_texture.c \
		  	
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./libft -lft

CC = gcc

INCLUDES = ./inc

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDES)  $(FLAGSMLX) $(LIBFT)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@echo "$(AT) CLEAN  $(NAME)  : OK"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@echo "$(AT) FCLEAN $(NAME)  : OK"

re: fclean all

.PHONY: all clean fclean re
