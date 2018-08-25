/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:25 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 16:01:18 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_epileptic_start(t_mlx *mlx)
{
	t_color col;

	ft_epileptic(&col);
	mlx->color = col;
	mlx->eyes->y += 0.03;
	mlx->eyes->x += 0.05;
	return (0);
}

int		ft_exit(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 75 || key == 44)
		ft_change_color(mlx);
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

int		ft_button_scale(int code, t_mlx *mlx)
{
	if (code == 69)
		mlx->eyes->incr *= 1.1;
	else if (code == 78)
		mlx->eyes->incr /= 1.1;
	return (0);
}

int		ft_press_button(int code, t_mlx *mlx)
{
	ft_move_w(code, mlx);
	if (code == 81)
		ft_epileptic_start(mlx);
	ft_button_scale(code, mlx);
	if (code == 86)
		mlx->eyes->y += 0.1;
	if (code == 88)
		mlx->eyes->y -= 0.1;
	if (code == 84)
		mlx->eyes->x += 0.1;
	if (code == 91)
		mlx->eyes->x -= 0.1;
	if (code == 87)
	{
		mlx->eyes->x = 0.06;
		mlx->eyes->y = 0.1;
		mlx->eyes->incr = 40;
	}
	ft_processing(mlx);
	ft_helper(mlx->mlx, mlx->window);
	return (0);
}
