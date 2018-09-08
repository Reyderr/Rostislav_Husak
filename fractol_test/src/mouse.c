/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:05:37 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/08 15:28:07 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_rescale(t_mlx *mlx)
{
	mlx->s_x = (mlx->old_x / mlx->scale + mlx->s_x) - ((mlx->scale / 1.3) / 2);
	mlx->s_x += ((mlx->scale / 1.3) / 2) - (mlx->old_x / (mlx->scale / 1.3));
	mlx->s_y = (mlx->old_y / mlx->scale + mlx->s_y) - ((mlx->scale / 1.3) / 2);
	mlx->s_y += ((mlx->scale / 1.3) / 2) - (mlx->old_y / (mlx->scale / 1.3));
	mlx->scale /= 1.3;
	mlx->maxiter--;
}

void	ft_scale(int x, int y, t_mlx *mlx)
{
	mlx->old_x = x;
	mlx->old_y = y;
	mlx->s_x = (x / mlx->scale + mlx->s_x) - ((mlx->scale * 1.3) / 2); 
	mlx->s_x += ((mlx->scale * 1.3) / 2) - (x / (mlx->scale * 1.3));
	mlx->s_y = (y / mlx->scale + mlx->s_y) - ((mlx->scale * 1.3) / 2);
	mlx->s_y += ((mlx->scale * 1.3) / 2) - (y / (mlx->scale * 1.3));
	mlx->scale *= 1.3;
	mlx->maxiter++;
}

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void	ft_scales(double mouseRe, double mouseIm, t_mlx *mlx)
{
	 double interpolation = 1.0 / mlx->scale;
     mlx->re_min = interpolate(mouseRe, mlx->re_min, interpolation);
     mlx->im_min = interpolate(mouseIm, mlx->im_min, interpolation);
     mlx->re_max = interpolate(mouseRe, mlx->re_max, interpolation);
     mlx->im_max = interpolate(mouseIm, mlx->im_max, interpolation);
}

int 	ft_mouse(int c, int x, int y, t_mlx *mlx)
{
	double mouseRe = (double)x / (WIN_WD / (mlx->re_max - mlx->re_min)) + mlx->re_min;
	double mouseIm = (double)y / (WIN_HG / (mlx->im_max - mlx->im_min)) + mlx->im_min;
	if (c == 4 || c == 1)
		{
			mlx->scale *= 1.01;
			mlx->maxiter++;
			ft_scales(mouseRe, mouseIm, mlx);
		}
	if (c == 5 || c == 2)
		{
			mlx->scale *= 0.9;
			mlx->maxiter--;
			ft_scales(mouseRe, mouseIm, mlx);
		}
	 ft_var(mlx);
	return (0);
}
