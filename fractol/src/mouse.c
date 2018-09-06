/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:05:37 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/05 12:45:06 by rhusak           ###   ########.fr       */
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

int 	ft_mouse(int c, int x, int y, t_mlx *mlx)
{
	if (c == 4 || c == 1)
		ft_scale(x, y, mlx);
	else if (c == 5 || c == 2)
		ft_rescale(mlx);
	ft_var(mlx);
	return (0);
}