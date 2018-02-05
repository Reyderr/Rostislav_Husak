#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhusak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 13:19:00 by rhusak            #+#    #+#              #
#    Updated: 2018/01/17 13:19:11 by rhusak           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fillit

SRC		= main.c checker.c \
		  algoritm.c map.c \
		  read.c \
		  ft_memdel.c ft_strsub.c ft_putendl.c ft_memset.c ft_putchar.c ft_putstr.c\

OBJ		= $(SRC:.c=.o)

INCLUDE = fillit.h

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)	

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all