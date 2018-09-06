/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:22:00 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/05 12:14:00 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void ft_iterations(t_mlx *mlx)
{
	mlx->maxiter++;
	if (mlx->fract == 1)
		ft_multi_mandelbrot(mlx);
	if (mlx->fract == 2)
		ft_multi_julia(mlx);
}

int		ft_exit(int key, t_mlx *mlx)
{
	(void)mlx;
	
	if (key == 53)
	{
		//system("leaks Fractol");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		ft_exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		m_juli(int x, int y, t_mlx *mlx)
{
	if ((x >= 0 && x <= WIN_WD) && (y >= 0 && y <= WIN_HG) &&
		(mlx->fract == 2))
	{
		mlx->rl = x *  0.000999;
		mlx->im = y * 0.000999;
		ft_multi_julia(mlx);
	}
	return (0);
}

int ft_press_button(int key, t_mlx *mlx)
{
	if (key == 75 || key == 44)
		ft_iterations(mlx);
	if (key == 69)
	{
		mlx->scale += 1.0;
		ft_var(mlx);
	}
	if (key == 78)
		mlx->scale -= 1.0;
	if (key == 87)
		ft_begin(mlx);
	ft_var(mlx);
	return (0);
}