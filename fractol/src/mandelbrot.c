/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:50:39 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/05 12:16:40 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>

void	ft_doub(float *real, float *imagine, float dx, float dy)
{
	float sq_real;
    float sq_imagine;
    float doub;

    sq_real = *real * *real;
    sq_imagine = *imagine * *imagine;
    doub = 2.0 * *real * *imagine;
    *real = sq_real - sq_imagine + dx;
    *imagine = doub + dy;
}

void	ft_m_c(int x, int y, t_mlx *mlx)
{
	float	real;
	float	imagine;
	float	dx;
	float	dy;
	int		n;

	dy = (y - WIN_HG / 2) / (0.5 * WIN_HG);
	dx = 1.5 * (x - WIN_WD / 2) / (0.5 * WIN_WD) - 0.5;
	real = 0;
    imagine = 0;
    n = 0;
    while (n < mlx->maxiter) 
    {
    	ft_doub(&real, &imagine, dx, dy);
    	if (real * real + imagine * imagine > 4) 
          	break; 
        n++;
   	}
    if (n < mlx->maxiter)
   		ft_pixel_color(mlx, x, y, n);
   	else
   		ft_pixel_color(mlx, x, y, n);
}

void	ft_multi_mandelbrot(t_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < WIN_HG)
	{
		x = 0;
		while(x < WIN_WD)
		{
			ft_m_c(x, y, mlx);
			x++;
		}
		y++;
	}
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}

