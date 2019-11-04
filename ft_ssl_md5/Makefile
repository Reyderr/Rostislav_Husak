#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 20:21:19 by rhusak            #+#    #+#              #
#    Updated: 2019/10/25 20:21:23 by rhusak           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

AT 		= \033[37;1;41m Attantion!!! \033[0m

NAME 	= ft_ssl

LIBF_F 	= ./libft
INCLUDE = -I ./inc

SRC 	=	src/main.c \
			src/heshing_md5.c \
			src/heshing_256.c \
			src/check.c \
			src/output.c \
			src/flag_corections.c \
			src/zero_add.c \
			src/error_hendl.c \
			src/sub.c \
			src/the_hendl.c \
			src/ft_pars.c \
			src/additional_sha256.c \
			src/sha512.c \
			src/sha384.c \
			src/additional_sha384.c \
			src/additional_sha512.c
			
FLAGS 	= -Wall -Wextra -Werror $(INCLUDE)

OBJ 	= $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	@gcc $(FLAGS) -c -o $@ $^
	@echo -n -

$(NAME): $(OBJ)
	@make -C $(LIBF_F)
	@gcc $(FLAGS) $(INCLUDE) -L $(LIBF_F) -lft -o $(NAME) $(OBJ)


clean:
	@rm -rf $(OBJ)
	@make -C $(LIBF_F) clean
	@echo "$(AT) CLEAN FT_SSL   : OK"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBF_F) fclean
	@echo "$(AT) FCLEAN FT_SSL  : OK"

re: fclean all clean
