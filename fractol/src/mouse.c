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

double		interp(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		ft_scales(double m_re, double m_im, t_mlx *mlx)
{
	mlx->interpolation = 1 / mlx->scale;
	mlx->re_min = interp(m_re, mlx->re_min, mlx->interpolation);
	mlx->im_min = interp(m_im, mlx->im_min, mlx->interpolation);
	mlx->re_max = interp(m_re, mlx->re_max, mlx->interpolation);
	mlx->im_max = interp(m_im, mlx->im_max, mlx->interpolation);
}

int			ft_mouse(int c, int x, int y, t_mlx *mlx)
{
	double m_re;
	double m_im;

	m_re = (double)x / (WIN_WD / (mlx->re_max - mlx->re_min)) + mlx->re_min;
	m_im = (double)y / (WIN_HG / (mlx->im_max - mlx->im_min)) + mlx->im_min;
	mlx->scale = 1;
	if (c == 4 || c == 1)
	{
		mlx->scale *= 1.2;
		mlx->maxiter++;
		ft_scales(m_re, m_im, mlx);
	}
	else if (c == 5 || c == 2)
	{
		mlx->scale /= 1.2;
		mlx->maxiter--;
		ft_scales(m_re, m_im, mlx);
	}
	ft_var(mlx);
	return (0);
}
