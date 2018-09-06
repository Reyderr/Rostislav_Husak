/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:03:13 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/05 12:09:16 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void 	ft_b_mandel(t_mlx *mlx)
{
	mlx->maxiter = 10;
	ft_multi_mandelbrot(mlx);
}

void	ft_b_julia(t_mlx *mlx)
{	
	mlx->rl = 0.835;
	mlx->im = 0.2321;
	mlx->scale = 400.0;
	mlx->maxiter = 10;
	ft_multi_julia(mlx);
}

void 	ft_var(t_mlx *mlx)
{
	if(mlx->fract == 1)
		ft_multi_mandelbrot(mlx);
	if(mlx->fract == 2)
		ft_multi_julia(mlx);
}

void	ft_begin(t_mlx *mlx)
{
	if(mlx->fract == 1)
		ft_b_mandel(mlx);
	if(mlx->fract == 2)
		ft_b_julia(mlx);
}
