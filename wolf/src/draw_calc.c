/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:55:28 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 17:22:58 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	ft_calc_bot_top(t_mlx *mlx, int y)
{
	mlx->bot.way = WIN_HG / (2. * y - WIN_HG);
	mlx->bot.wt = (mlx->bot.way
		- mlx->bot.p_way) / (mlx->bot.w_w - mlx->bot.p_way);
	mlx->bot.c_bot_x = mlx->bot.wt * mlx->bot.b_x
	+ (1.0 - mlx->bot.wt) * mlx->map->p_x;
	mlx->bot.c_bot_y = mlx->bot.wt * mlx->bot.b_y
	+ (1.0 - mlx->bot.wt) * mlx->map->p_y;
	mlx->bot.bot_tex_x = (int)(mlx->bot.c_bot_x * T_W) % T_W;
	mlx->bot.bot_tex_y = (int)(mlx->bot.c_bot_y * T_H) % T_H;
}

int		ft_f_side(t_mlx *mlx)
{
	if (mlx->wall == 0)
	{
		if ((mlx->iter_x == -1 && mlx->iter_y == 1)
			|| (mlx->iter_x == -1 && mlx->iter_y == -1))
			return (10);
		if ((mlx->iter_x == 1 && mlx->iter_y == -1)
			|| (mlx->iter_x == 1 && mlx->iter_y == 1))
			return (mlx->num);
	}
	if ((mlx->iter_x == -1 && mlx->iter_y == 1)
		|| (mlx->iter_x == 1 && mlx->iter_y == 1))
		return (5);
	else
		return (8);
}

int		ft_side(t_mlx *mlx)
{
	if (mlx->f_side == 1)
		return (ft_f_side(mlx));
	else
		return (mlx->num);
}
