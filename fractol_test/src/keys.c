/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:22:00 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 14:19:13 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void ft_iterations(t_mlx *mlx)
{
	mlx->maxiter++;
	ft_var(mlx);
}

void ft_lock(t_mlx *mlx)
{
	if (mlx->lock == 0)
		mlx->lock = 1;
	else
		mlx->lock = 0;
	ft_var(mlx);
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
		(mlx->fract == 2) && (mlx->lock == 0))
	{
		mlx->rl = x * 0.002;
		mlx->im = y * 0.002;
		ft_multi_julia(mlx);
	}
	ft_str(mlx);
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
	if (key == 37)
		ft_lock(mlx);
	if (key == 78)
		mlx->scale -= 1.0;
	if (key == 87)
		ft_begin(mlx);
	ft_var(mlx);
	return (0);
}