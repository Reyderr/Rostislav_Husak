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

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void	ft_b_spider(t_mlx *mlx)
{
	mlx->maxiter = 50;
	ft_var(mlx);
}

void	ft_b_bship(t_mlx *mlx)
{
	mlx->maxiter = 50;
	mlx->scale = 300;
	ft_var(mlx);
}

void	ft_b_liambda(t_mlx *mlx)
{
	mlx->maxiter = 50;
	ft_var(mlx);
}

void 	ft_b_mandel(t_mlx *mlx)
{
	mlx->maxiter = 5000;
	ft_var(mlx);
}

void	ft_b_julia(t_mlx *mlx)
{	
	mlx->rl = 0.835;
	mlx->im = 0.2321;
	mlx->scale = 300;
	mlx->maxiter = 50;
	mlx->lock = 0;
	ft_var(mlx);
}

void 	ft_var(t_mlx *mlx)
{
	if(mlx->fract == 1)
		ft_multi_mandelbrot(mlx);
	if(mlx->fract == 2)
		ft_multi_julia(mlx);
	if(mlx->fract == 3)
		ft_multi_liambda(mlx);
	if(mlx->fract == 4)
		ft_multi_bship(mlx);
	if(mlx->fract == 5)
		ft_multi_spider(mlx);
	ft_str(mlx);

}

void	ft_begin(t_mlx *mlx)
{

	if(mlx->fract == 1)
		ft_b_mandel(mlx);
	if(mlx->fract == 2)
		ft_b_julia(mlx);
	if(mlx->fract == 3)
		ft_b_liambda(mlx);
	if(mlx->fract == 4)
		ft_b_bship(mlx);
	if(mlx->fract == 5)
		ft_b_spider(mlx);
	ft_str(mlx);
}
