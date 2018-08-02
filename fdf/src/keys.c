/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:25 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/01 17:21:46 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_epileptic_start(t_mlx *mlx)
{
	t_color col;

	ft_epileptic(&col);
	mlx->color = col;
	mlx->cam->y += 0.03;
	mlx->cam->x += 0.05;
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
		mlx->cam->scale *= 1.1;
	else if (code == 78)
		mlx->cam->scale /= 1.1;
	return (0);
}

int		ft_press_button(int code, t_mlx *mlx)
{
	ft_move_w(code, mlx);
	if (code == 81)
		ft_epileptic_start(mlx);
	ft_button_scale(code, mlx);
	if (code == 86)
		mlx->cam->y += 0.1;
	if (code == 88)
		mlx->cam->y -= 0.1;
	if (code == 84)
		mlx->cam->x += 0.1;
	if (code == 91)
		mlx->cam->x -= 0.1;
	if (code == 87)
	{
		mlx->cam->x = 0;
		mlx->cam->y = 0;
		mlx->cam->scale = 40;
	}
	ft_render(mlx);
	ft_helper(mlx->mlx, mlx->window);
	return (0);
}
