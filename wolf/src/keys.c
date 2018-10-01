/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:17:25 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 17:55:26 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_button_pressig_1(int key, t_mlx *mlx)
{
	if (key == 37 && mlx->init == 1)
		ft_lock(mlx);
	if (key == 17 && mlx->init == 1)
	{
		ft_n_text(mlx);
		ft_chtexture(mlx);
	}
	if (key == 3 && mlx->init == 1)
		ft_f_text(mlx);
}

void		ft_m_x(t_mlx *mlx)
{
	mlx->od_x = mlx->d_x;
	mlx->d_x = mlx->d_x * cos((mlx->oldm - mlx->maus_x)
		* 0.007) - mlx->d_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
	mlx->d_y = mlx->od_x * sin((mlx->oldm - mlx->maus_x)
		* 0.007) + mlx->d_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
	mlx->o_pl_x = mlx->pl_x;
	mlx->pl_x = mlx->pl_x * cos((mlx->oldm - mlx->maus_x)
		* 0.007) - mlx->pl_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
	mlx->pl_y = mlx->o_pl_x * sin((mlx->oldm - mlx->maus_x)
		* 0.007) + mlx->pl_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
}

int			ft_maus(int x, int y, t_mlx *mlx)
{
	mlx->oldm = mlx->maus_x;
	mlx->maus_x = x;
	if ((x >= 0 && x <= WIN_WD) && (y >= 0 && y <= WIN_HG) && (mlx->lock == 0))
	{
		if (mlx->maus_x > mlx->oldm)
		{
			mlx->od_x = mlx->d_x;
			mlx->d_x = mlx->d_x * cos((mlx->oldm - mlx->maus_x)
				* 0.007) - mlx->d_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
			mlx->d_y = mlx->od_x * sin((mlx->oldm - mlx->maus_x)
				* 0.007) + mlx->d_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
			mlx->o_pl_x = mlx->pl_x;
			mlx->pl_x = mlx->pl_x * cos((mlx->oldm - mlx->maus_x)
				* 0.007) - mlx->pl_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
			mlx->pl_y = mlx->o_pl_x * sin((mlx->oldm - mlx->maus_x)
				* 0.007) + mlx->pl_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
		}
		if (mlx->maus_x < mlx->oldm)
			ft_m_x(mlx);
	}
	ft_calc(mlx);
	return (0);
}

int			ft_button_pressig(int key, t_mlx *mlx)
{
	if ((key == 126 || key == 125 || key == 1 || key == 13) && mlx->init == 1)
		ft_move_db(key, mlx);
	if ((key == 123 || key == 124 || key == 2 || key == 0) && mlx->init == 1)
		ft_move_rl(key, mlx);
	if ((key == 126 || key == 125) && mlx->init == 0)
	{
		ft_i(mlx);
		ft_rend_screen(mlx);
	}
	if ((key == 36 || key == 76) && mlx->init == 0)
	{
		mlx->init = 1;
		if (mlx->exit == 1)
			exit(EXIT_SUCCESS);
		ft_wolf(mlx);
	}
	ft_button_pressig_1(key, mlx);
	if (mlx->init == 1)
		ft_calc(mlx);
	return (0);
}
