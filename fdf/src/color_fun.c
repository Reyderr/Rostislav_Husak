/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:50:54 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/01 17:17:42 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_change_color(t_mlx *mlx)
{
	t_color color;

	ft_epileptic(&color);
	mlx->color = color;
	ft_render(mlx);
	ft_helper(mlx->mlx, mlx->window);
	return (0);
}

void	ft_epileptic(t_color *color)
{
	color->r = rand() % 255 + 1;
	color->g = rand() % 255 + 1;
	color->b = rand() % 255 + 1;
}

void	ft_pixel_color(t_mlx *mlx, int x, int y)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = mlx->color.r;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = mlx->color.g;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = mlx->color.b;
}
