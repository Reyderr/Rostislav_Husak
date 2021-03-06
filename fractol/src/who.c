/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:03:13 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/08 15:43:14 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_b_liambda(t_mlx *mlx)
{
	mlx->maxiter = 50;
	mlx->re_min = -2;
	mlx->re_max = 4;
	mlx->im_min = -2.2;
	mlx->im_max = mlx->im_min + (mlx->re_max - mlx->re_min) * WIN_HG / WIN_WD;
	ft_var(mlx);
}

void	ft_b_mandel(t_mlx *mlx)
{
	mlx->maxiter = 50;
	ft_var(mlx);
}

void	ft_b_julia(t_mlx *mlx)
{
	mlx->rl = -0.4;
	mlx->im = 0.6;
	mlx->maxiter = 50;
	mlx->lock = 0;
	mlx->re_min = -2;
	mlx->re_max = 4;
	mlx->im_min = -1.2;
	mlx->im_max = mlx->im_min + (mlx->re_max - mlx->re_min) * WIN_HG / WIN_WD;
	ft_var(mlx);
}

void	ft_var(t_mlx *mlx)
{
	if (mlx->fract == 1)
		ft_multi_mandelbrot(mlx);
	if (mlx->fract == 2)
		ft_multi_julia(mlx);
	if (mlx->fract == 3)
		ft_multi_bship(mlx);
	if (mlx->fract == 4)
		ft_multi_liambda(mlx);
	if (mlx->fract == 5)
		ft_multi_spider(mlx);
	ft_str(mlx);
}

void	ft_begin(t_mlx *mlx)
{
	mlx->move_x = 0.1;
	mlx->move_y = 0.1;
	mlx->re_min = -2.0;
	mlx->re_max = 1.0;
	mlx->im_min = -1.2;
	mlx->im_max = mlx->im_min + (mlx->re_max - mlx->re_min) * WIN_HG / WIN_WD;
	mlx->rd = 220;
	mlx->gr = 10;
	mlx->bl = 2;
	if (mlx->fract == 1)
		ft_b_mandel(mlx);
	if (mlx->fract == 2)
		ft_b_julia(mlx);
	if (mlx->fract == 3)
		ft_b_bship(mlx);
	if (mlx->fract == 4)
		ft_b_liambda(mlx);
	if (mlx->fract == 5)
		ft_b_spider(mlx);
}
