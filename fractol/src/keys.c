/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:22:00 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 14:19:13 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

void	ft_move(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->move_x += 0.09;
	if (key == 124)
		mlx->move_x -= 0.09;
	if (key == 125)
		mlx->move_y -= 0.09;
	if (key == 126)
		mlx->move_y += 0.09;
	ft_var(mlx);
}

int		m_juli(int x, int y, t_mlx *mlx)
{
	if ((x >= 0 && x <= WIN_WD) && (y >= 0 && y <= WIN_HG) &&
		(mlx->fract == 2) && (mlx->lock == 0))
	{
		mlx->rl = x * 0.002;
		mlx->im = y * 0.002;
		ft_multi_julia(mlx);
	}
	ft_str(mlx);
	return (0);
}

int		ft_press_button(int key, t_mlx *mlx)
{
	if (key == 78 || key == 69)
		ft_iterations(key, mlx);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(key, mlx);
	if (key == 83 || key == 84 || key == 85 || key == 86 || key == 87)
		ft_choise(key, mlx);
	if (key == 37)
		ft_lock(mlx);
	if (key == 36)
		ft_epileptic(mlx);
	if (key == 81 || key == 75 || key == 67)
		ft_rand_col(key, mlx);
	if (key == 82)
		ft_begin(mlx);
	ft_var(mlx);
	return (0);
}
