#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhusak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 12:17:05 by rhusak            #+#    #+#              #
#    Updated: 2017/08/10 18:12:41 by rhusak           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=ft_display_file
GCC=gcc
SRC=ft_display_file.c

all: $(NAME)

$(NAME):
	@$(GCC) -Wall -Werror -Wextra -c $(SRC)
	@$(GCC) -o $(NAME) ft_display_file.o

clean:
	@rm -f ft_display_file.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
