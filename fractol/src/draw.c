/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:02:47 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/08 14:20:58 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_color_set(t_mlx *mlx, int n)
{
	float ind;

	ind = n + 1 - (log(2) / 1) / log(2);
	mlx->color.r = (sin(0.016 * ind + 4) * 230 + mlx->rd);
	mlx->color.g = (sin(0.023 * ind + 2) * 230 + mlx->gr);
	mlx->color.b = (sin(0.01 * ind + 1) * 230 + mlx->bl);
}

void	ft_pixel_color(t_mlx *mlx, int x, int y, int n)
{
	ft_color_set(mlx, n);
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = mlx->color.r;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = mlx->color.g;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = mlx->color.b;
}
