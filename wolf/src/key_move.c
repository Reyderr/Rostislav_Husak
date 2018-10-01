/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:26:52 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 17:52:53 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	ft_db2(t_mlx *mlx)
{
	{
		if (!mlx->map->sq[(int)(mlx->map->p_x - mlx->d_x
			* 1)][(int)(mlx->map->p_y)] || ((mlx->map->sq[(int)(mlx->map->p_x
				- mlx->d_x * 1)][(int)(mlx->map->p_y)] == 7
				|| mlx->map->sq[(int)(mlx->map->p_x - mlx->d_x
					* 1)][(int)(mlx->map->p_y)] == 13
					|| mlx->map->sq[(int)(mlx->map->p_x - mlx->d_x
						* 1)][(int)(mlx->map->p_y)] == 8)
			&& mlx->n_text != 1))
			mlx->map->p_x -= mlx->d_x * 0.2;
		if (!mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y - mlx->d_y
			* 1)] || ((mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y
				- mlx->d_y * 1)] == 7
			|| mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y + mlx->d_y
				* 1)] == 13
			|| mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y + mlx->d_y
				* 1)] == 8) && mlx->n_text != 1))
			mlx->map->p_y -= mlx->d_y * 0.2;
	}
}

void	ft_port2(t_mlx *mlx)
{
	if ((mlx->map->sq[(int)(mlx->map->p_x + mlx->d_x
		* 1)][(int)(mlx->map->p_y)] == 8
		|| mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y + mlx->d_y
			* 1)] == 8) && mlx->n_text != 1 && mlx->map->port1_y
		&& mlx->map->c != 1)
	{
		mlx->d_x = -0.070737;
		mlx->d_y = 0.997495;
		mlx->pl_x = 0.698246;
		mlx->pl_y = 0.049516;
		mlx->map->p_x = mlx->map->port1_x + 0.5;
		mlx->map->p_y = mlx->map->port1_y + 1.5;
	}
}

void	ft_port1(t_mlx *mlx)
{
	if ((mlx->map->sq[(int)(mlx->map->p_x + mlx->d_x
		* 1)][(int)(mlx->map->p_y)] == 7
		|| mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y + mlx->d_y
			* 1)] == 7) && mlx->n_text != 1 && mlx->map->port2_x
		&& mlx->map->c != 1)
	{
		ft_begin(mlx);
		mlx->d_x = -0.070737;
		mlx->d_y = 0.932039;
		mlx->pl_x = 0.652427;
		mlx->pl_y = 0.253650;
		mlx->map->p_x = mlx->map->port2_x + 0.5;
		mlx->map->p_y = mlx->map->port2_y + 1.5;
	}
}

void	ft_move_rl(int key, t_mlx *mlx)
{
	if (key == 123 || key == 0)
	{
		mlx->od_x = mlx->d_x;
		mlx->d_x = mlx->d_x * cos(0.06) - mlx->d_y * sin(0.06);
		mlx->d_y = mlx->od_x * sin(0.06) + mlx->d_y * cos(0.06);
		mlx->o_pl_x = mlx->pl_x;
		mlx->pl_x = mlx->pl_x * cos(0.06) - mlx->pl_y * sin(0.06);
		mlx->pl_y = mlx->o_pl_x * sin(0.06) + mlx->pl_y * cos(0.06);
	}
	if (key == 124 || key == 2)
	{
		mlx->od_x = mlx->d_x;
		mlx->d_x = mlx->d_x * cos(-0.06) - mlx->d_y * sin(-0.06);
		mlx->d_y = mlx->od_x * sin(-0.06) + mlx->d_y * cos(-0.06);
		mlx->o_pl_x = mlx->pl_x;
		mlx->pl_x = mlx->pl_x * cos(-0.06) - mlx->pl_y * sin(-0.06);
		mlx->pl_y = mlx->o_pl_x * sin(-0.06) + mlx->pl_y * cos(-0.06);
	}
}

void	ft_move_db(int key, t_mlx *mlx)
{
	if (key == 126 || key == 13)
	{
		if (!mlx->map->sq[(int)(mlx->map->p_x + mlx->d_x
			* 1)][(int)(mlx->map->p_y)] || ((mlx->map->sq[(int)(mlx->map->p_x
				+ mlx->d_x * 1)][(int)(mlx->map->p_y)] == 7
				|| mlx->map->sq[(int)(mlx->map->p_x + mlx->d_x
					* 1)][(int)(mlx->map->p_y)]
					== 13 || mlx->map->sq[(int)(mlx->map->p_x + mlx->d_x
					* 1)][(int)(mlx->map->p_y)] == 8) && mlx->n_text != 1))
			mlx->map->p_x += mlx->d_x * 0.2;
		if (!mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y + mlx->d_y
			* 1)] || ((mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y
				+ mlx->d_y * 1)] == 7
			|| mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y
				+ mlx->d_y * 1)] == 13
			|| mlx->map->sq[(int)(mlx->map->p_x)][(int)(mlx->map->p_y
				+ mlx->d_y * 1)] == 8) && mlx->n_text != 1))
			mlx->map->p_y += mlx->d_y * 0.2;
	}
	if (key == 125 || key == 1)
		ft_db2(mlx);
	ft_port1(mlx);
	ft_port2(mlx);
}
