# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2018/08/26 14:53:28 by rhusak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AT 		= \033[37;1;41m Attantion!!! \033[0m


NAME	= libft.a
SRC		= $(shell ls | grep -E "ft_.+\.c") \
		  get_next_line.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "-> \033[36 sProject Compile :\033[0m OK "

%.o:%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo -n -

clean:
	@rm -rf $(OBJ)
	@echo "$(AT) CLEAN LIBFT    : OK"

fclean:
	@rm -rf $(NAME)
	@echo "$(AT) FCLEAN LIBFT   : OK"

re: fclean all
