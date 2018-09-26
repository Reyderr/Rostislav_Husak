/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:00:10 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/24 11:50:33 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int		ft_strcol(char *str, char *color)
{
	if (color)
	{
		write(1, color, ft_strlen(color));
		write(1, str, ft_strlen(str));
		write(1, END, ft_strlen(END));
	}
	return(1);
}

void	ft_command(void)
{
	ft_strcol("\t COMMAND\n", YELLOW);
	ft_strcol("\tMouse\n---------------------------\nMove mouse to move image\
		\n---------------------------\n", LIGT_BLUE);
	ft_strcol("\tMove\n---------------------------\nPress arrow or W, A, S, D\
		\nto move \n---------------------------\n", GREEN);
	ft_strcol("\tOther\n---------------------------\nPress 'L' - stop\
		\ncalculate mouse move\n---------------------------\n", PURPLE);
}