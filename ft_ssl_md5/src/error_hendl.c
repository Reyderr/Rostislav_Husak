/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:30:38 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:30:40 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_erro(int num_er)
{
	if (num_er == 1)
		ft_putendl("Invalid command name!\nusage: ./ft_ssl command\
			[options] [args]");
	exit(1);
}

void		ft_erro_comand(char *str)
{
	ft_putstr("Invalid command: '");
	ft_putstr(str);
	ft_putendl("'.\n");
	ft_putendl("Standart commands:\n\nMessage Digest commands:\nmd5\nsha256");
	ft_putendl("sha384\nsha512\n");
	ft_putendl("Cipher commands:");
	exit(1);
}

void		ft_wrong(char *str)
{
	ft_putstr(" ");
	ft_putendl(str);
}

void		ft_error_init(void)
{
	ft_putendl("ERROR: error initiate command");
	exit(1);
}
