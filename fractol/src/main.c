/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:06:58 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 17:19:00 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_strcol(char *str, char *color)
{
	if (color)
	{
		write(1, color, ft_strlen(color));
		write(1, str, ft_strlen(str));
		write(1, END, ft_strlen(END));
	}
}

void	ft_printing(void)
{
	ft_strcol("\t COMMAND\n", YELLOW);
	ft_strcol("\tOn numpad\n---------------------------\
		\n'1' - mandelbrot \
		\n'2' - julia\n'3' - burn ship \
		\n'4' - liambda\n'5' - spider\n\
		\n'+' - add iterations\n'-' - decrease iterations\
		\n'0' - start position\n\tChange spectral\n\t  sensitivity\
		\n'=' - change red\n'/' - change green\n'*' - change blue\
		\n'Enter' - epileptic\n---------------------------\n", RED);
	ft_strcol("\tMause\n---------------------------\nLMB - zoom in\
		\nRMB - zoom out\nOr twist a wheel\n---------------------------\n",
		LIGT_BLUE);
	ft_strcol("\tArrow\n---------------------------\nPress arrow\
		\nto move image\n---------------------------\n", GREEN);
	ft_strcol("\tOther\n---------------------------\nPress 'L' - stop\
		\nre_calculate julia\n---------------------------\n", PURPLE);
}

int		ft_choose(char **av, t_mlx *mlx)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mlx->fract = 1;
	else if (ft_strcmp(av[1], "julia") == 0)
		mlx->fract = 2;
	else if (ft_strcmp(av[1], "bship") == 0)
		mlx->fract = 3;
	else if (ft_strcmp(av[1], "liambda") == 0)
		mlx->fract = 4;
	else if (ft_strcmp(av[1], "spider") == 0)
		mlx->fract = 5;
	else
	{
		ft_helper();
		return (0);
	}
	ft_printing();
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	int		fd;

	fd = open(av[1], O_DIRECTORY);
	if (ac != 2 || fd >= 0)
	{
		ft_helper();
		return (0);
	}
	if ((mlx = ft_start()) == NULL)
		return (ft_error("ERROR : mlx create error"));
	if (ft_choose(av, mlx) == 0)
		return (0);
	ft_begin(mlx);
	mlx_hook(mlx->window, 6, 1L < 6, m_juli, mlx);
	mlx_hook(mlx->window, 2, 3, ft_press_button, mlx);
	mlx_key_hook(mlx->window, ft_exit, mlx);
	mlx_hook(mlx->window, 17, 0, ft_exit_x, mlx);
	mlx_mouse_hook(mlx->window, ft_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
