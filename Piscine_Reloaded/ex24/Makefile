#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhusak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/07 16:59:53 by rhusak            #+#    #+#              #
#    Updated: 2017/08/08 21:00:36 by rhusak           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libft.a
SRC=./srcs/*.c
HEADER=./includes/*.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -I$(HEADER)
	ar rc $(NAME) *.o

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
