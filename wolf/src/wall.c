/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:49:08 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 18:17:31 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_wall(t_mlx *mlx)
{
	if (mlx->wall == 0)
		mlx->mv_wall = (mlx->map->wd - mlx->map->p_x
			+ (1 - mlx->iter_x) / 2) / mlx->rd_x;
	else
		mlx->mv_wall = (mlx->map->hg - mlx->map->p_y
			+ (1 - mlx->iter_y) / 2) / mlx->rd_y;
}

void		ft_wall_0(t_mlx *mlx)
{
	if (mlx->wall == 0)
		mlx->x_w = mlx->map->p_y + mlx->mv_wall * mlx->rd_y;
	else
		mlx->x_w = mlx->map->p_x + mlx->mv_wall * mlx->rd_x;
}
