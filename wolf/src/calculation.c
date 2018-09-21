/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:23:53 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/21 11:25:37 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"


void		ft_bg(t_mlx *mlx, int x)
{
	mlx->cam = 2 * x / (double)(WIN_WD) - 1;
	mlx->rd_x = mlx->d_x + mlx->pl_x * mlx->cam;
	mlx->rd_y = mlx->d_y + mlx->pl_y * mlx->cam;
	mlx->map->wd = (int)(mlx->map->p_x);
	mlx->map->hg = (int)(mlx->map->p_y);
	mlx->d_dt_x = fabs(1 / mlx->rd_x);
	mlx->d_dt_y = fabs(1 / mlx->rd_y);
	mlx->touch = 0;
}

void		ft_rd(t_mlx *mlx)
{	
	if (mlx->rd_x < 0)
		{
			mlx->iter_x = -1;
			mlx->s_dt_x = (mlx->map->p_x - mlx->map->wd) * mlx->d_dt_x;
		}
		else
		{
			mlx->iter_x = 1;
			mlx->s_dt_x = (mlx->map->wd + 1.0 - mlx->map->p_x) * mlx->d_dt_x;
		}
		if (mlx->rd_y < 0)
		{
			mlx->iter_y = -1;
			mlx->s_dt_y = (mlx->map->p_y - mlx->map->hg) * mlx->d_dt_y;
		}
		else
		{
			mlx->iter_y = 1;
			mlx->s_dt_y = (mlx->map->hg + 1.0 - mlx->map->p_y) * mlx->d_dt_y;
		}
}

void		ft_touch(t_mlx *mlx)
{
	while(mlx->touch == 0)
		{
			if (mlx->s_dt_x < mlx->s_dt_y)
			{
				mlx->s_dt_x += mlx->d_dt_x;
				mlx->map->wd += mlx->iter_x;
				mlx->wall = 0;
			}
			else
			{
				mlx->s_dt_y += mlx->d_dt_y;
				mlx->map->hg += mlx->iter_y;
				mlx->wall = 1;
			}
			if (mlx->map->sq[mlx->map->wd][mlx->map->hg] > 0)
				mlx->touch = 1;
		}
}

void		ft_wall(t_mlx *mlx)
{
	if (mlx->wall == 0)
			mlx->mv_wall = (mlx->map->wd - mlx->map->p_x + (1 - mlx->iter_x) / 2)  / mlx->rd_x;
		else
			mlx->mv_wall = (mlx->map->hg - mlx->map->p_y + (1 - mlx->iter_y) / 2)  / mlx->rd_y;
}

void		ft_calc(t_mlx *mlx)
{
	int x;

	x = 0;
	while (x < WIN_WD)
	{
		ft_bg(mlx, x);
		ft_rd(mlx);	
		ft_touch(mlx);
		ft_wall(mlx);
		mlx->line_hg = (int)(WIN_HG / mlx->mv_wall);
		mlx->s_rend = -mlx->line_hg / 2 + WIN_HG / 2;
		if (mlx->s_rend < 0)
			mlx->s_rend = 0;
		mlx->e_rend = mlx->line_hg / 2 + WIN_HG / 2;
		if(mlx->e_rend >= WIN_HG)
			mlx->e_rend = WIN_HG - 1;
		if (mlx->map->sq[mlx->map->wd][mlx->map->hg] == 1)
			ft_color_set(mlx, 191, 244, 66);
		else
			ft_color_set(mlx, 200, 100, 10);
		ft_draw(mlx, x); 
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}