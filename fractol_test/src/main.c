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

int		ft_choose(char **av, t_mlx *mlx)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mlx->fract = 1;
	else if (ft_strcmp(av[1], "julia") == 0)
		mlx->fract = 2;
	else if (ft_strcmp(av[1], "liambda") == 0)
		mlx->fract = 3;
	else if (ft_strcmp(av[1], "bship") == 0)
		mlx->fract = 4;
	else if (ft_strcmp(av[1], "spider") == 0)
		mlx->fract = 5;
	else
	{
		ft_helper();
		return (0);
	}
	
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if((mlx = ft_start()) == NULL)
		return(ft_error("ERROR : mlx create error"));
	mlx->re_min = -2.0;
	mlx->re_max = 1.0;
	mlx->im_min = -1.2;
	mlx->im_max = mlx->im_min + (mlx->re_max - mlx->re_min) * WIN_HG/WIN_WD;
	mlx->scale = 1;
	if (ac != 2)
	{
		ft_helper();
		return(0);
	}
	if(ft_choose(av, mlx) == 0)
		return(0);
	ft_begin(mlx);
	mlx_hook(mlx->window, 6, 1L < 6, m_juli, mlx);
	mlx_hook(mlx->window, 2, 3, ft_press_button, mlx);
	mlx_key_hook(mlx->window, ft_exit, mlx);
	mlx_hook(mlx->window, 17, 0, ft_exit_x, mlx);
	mlx_mouse_hook(mlx->window, ft_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}