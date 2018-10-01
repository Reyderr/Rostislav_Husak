/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:00:10 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 17:24:37 by rhusak           ###   ########.fr       */
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
	return (1);
}

int		ft_exit(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		ft_exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void	ft_command(void)
{
	ft_strcol("\t COMMAND\n", YELLOW);
	ft_strcol("\tMouse\n---------------------------\nMove mouse to move image\
		\n---------------------------\n", LIGT_BLUE);
	ft_strcol("\tMove\n---------------------------\nPress arrow or W, A, S, D\
		\nto move \n---------------------------\n", GREEN);
	ft_strcol("\tOther\n---------------------------\nPress 'L' - stop\
		\ncalculate mouse move\nPress 'T' - change texture pack\
		\nPress 'F' - on/off 4 side\
		\n---------------------------\n", PURPLE);
}
