/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:17:25 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/21 11:06:59 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/wolf.h"

void		ft_lock(t_mlx *mlx)
{
	if (mlx->lock == 0)
		mlx->lock = 1;
	else
		mlx->lock = 0;
}

int		ft_exit(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		ft_exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	ft_move_rl(int key, t_mlx *mlx)
{
	if (key == 123)
	{
		mlx->od_x = mlx->d_x;
		mlx->d_x = mlx->d_x * cos(0.06) - mlx->d_y * sin(0.06);
		mlx->d_y = mlx->od_x * sin(0.06) + mlx->d_y * cos(0.06);
		 mlx->o_pl_x  = mlx->pl_x;
		 mlx->pl_x = mlx->pl_x * cos(0.06) - mlx->pl_y * sin(0.06);
		 mlx->pl_y = mlx->o_pl_x * sin(0.06) + mlx->pl_y * cos(0.06);
	}
	if (key == 124)
	{
		mlx->od_x = mlx->d_x;
		mlx->d_x = mlx->d_x * cos(-0.06) - mlx->d_y * sin(-0.06);
		mlx->d_y = mlx->od_x * sin(-0.06) + mlx->d_y * cos(-0.06);
		 mlx->o_pl_x  = mlx->pl_x;
		 mlx->pl_x = mlx->pl_x * cos(-0.06) - mlx->pl_y * sin(-0.06);
		 mlx->pl_y = mlx->o_pl_x * sin(-0.06) + mlx->pl_y * cos(-0.06);
	}
}

void	ft_move_db(int key, t_mlx *mlx)
{
	if (key == 126)
	{
		if (!mlx->map->sq[(int)(mlx->map->p_x + mlx->d_x * 1)][(int)(mlx->map->p_y)] )
			mlx->map->p_x += mlx->d_x * 0.3;
		if (!mlx->map->sq[(int)(mlx->map->p_x )][(int)(mlx->map->p_y + mlx->d_y * 1)] )
			mlx->map->p_y += mlx->d_y * 0.3;
	}
	if (key == 125)
	{
		if (!mlx->map->sq[(int)(mlx->map->p_x - mlx->d_x * 1)][(int)(mlx->map->p_y)] )
			mlx->map->p_x -= mlx->d_x * 0.3;
		if (!mlx->map->sq[(int)(mlx->map->p_x )][(int)(mlx->map->p_y - mlx->d_y * 1)] )
			mlx->map->p_y -= mlx->d_y * 0.3;
	}
	
}

int	ft_maus(int x, int y, t_mlx *mlx)
{
	mlx->oldm  = mlx->maus_x;
	mlx->maus_x = x;
	if ((x >= 0 && x <= WIN_WD) && (y >= 0 && y <= WIN_HG) && (mlx->lock == 0))
	{	
		if (mlx->maus_x > mlx->oldm)
		{
			mlx->od_x = mlx->d_x;
			mlx->d_x = mlx->d_x * cos((mlx->oldm - mlx->maus_x) * 0.007) - mlx->d_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
			mlx->d_y = mlx->od_x * sin((mlx->oldm - mlx->maus_x) * 0.007) + mlx->d_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
			 mlx->o_pl_x  = mlx->pl_x;
			 mlx->pl_x = mlx->pl_x * cos((mlx->oldm - mlx->maus_x) * 0.007) - mlx->pl_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
			 mlx->pl_y = mlx->o_pl_x * sin((mlx->oldm - mlx->maus_x) * 0.007) + mlx->pl_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
		}
		if (mlx->maus_x < mlx->oldm)
		{
			mlx->od_x = mlx->d_x;
			mlx->d_x = mlx->d_x * cos((mlx->oldm - mlx->maus_x) * 0.007) - mlx->d_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
			mlx->d_y = mlx->od_x * sin((mlx->oldm - mlx->maus_x) * 0.007) + mlx->d_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
			 mlx->o_pl_x  = mlx->pl_x;
			 mlx->pl_x = mlx->pl_x * cos((mlx->oldm - mlx->maus_x) * 0.007) - mlx->pl_y * sin((mlx->oldm - mlx->maus_x) * 0.007);
			 mlx->pl_y = mlx->o_pl_x * sin((mlx->oldm - mlx->maus_x) * 0.007) + mlx->pl_y * cos((mlx->oldm - mlx->maus_x) * 0.007);
		}
	}
	ft_calc(mlx);
return (0);
}

int	ft_button_pressig(int key, t_mlx *mlx)
{
	if (key == 126 || key == 125 )
		ft_move_db(key, mlx);
	if (key == 123 || key ==124)
		ft_move_rl(key, mlx);
	if (key == 37 )
		ft_lock(mlx);
	ft_calc(mlx);
	return(0);
}
