/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:06:24 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/19 17:25:53 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	ft_color_set(t_mlx *mlx, int r, int g, int b)
{
	mlx->color.r = r;
	mlx->color.g = g;
	mlx->color.b = b;
}

void	ft_pixel_color(t_mlx *mlx, int x, int y)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = mlx->color.b;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = mlx->color.g;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = mlx->color.r;
}

void	ft_pixel_color2(t_mlx *mlx, int x, int y , int color)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = color;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = color>>8;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = color>>16;
}
void	ft_draw(t_mlx *mlx, int x)
{
	int y;
	y = 0;
	while (y <  mlx->s_rend)
	{
		ft_pixel_color2(mlx, x, y, 0x425cf4);
		y++;
	}
	while(y < mlx->e_rend)
	{
		ft_pixel_color(mlx, x, y);
		y++;
	}
	while(y < WIN_HG)
	{
		ft_pixel_color2(mlx, x, y, 0x000000);
		y++;
	}
}