/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:06:24 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 17:28:49 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_lock(t_mlx *mlx)
{
	if (mlx->lock == 0)
		mlx->lock = 1;
	else
		mlx->lock = 0;
}

void		ft_pixel_color_bot(t_mlx *mlx, int x, int y)
{
	mlx->picture->addr[y
		* mlx->picture->sz_line + 4
		* x] = mlx->texture[4].addr[mlx->bot.bot_tex_y
		* mlx->texture[4].sz_line + 4 * mlx->bot.bot_tex_x];
	mlx->picture->addr[y * mlx->picture->sz_line
		+ 4 * x + 1] = mlx->texture[4].addr[mlx->bot.bot_tex_y
		* mlx->texture[4].sz_line + 4 * mlx->bot.bot_tex_x + 1];
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x + 2] = mlx->texture[4].addr[mlx->bot.bot_tex_y
		* mlx->texture[4].sz_line
		+ 4 * mlx->bot.bot_tex_x + 2];
}

void		ft_pixel_color_top(t_mlx *mlx, int x, int y)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x] = mlx->texture[3].addr[mlx->bot.bot_tex_y
		* mlx->texture[3].sz_line + 4 * mlx->bot.bot_tex_x];
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x + 1] = mlx->texture[3].addr[mlx->bot.bot_tex_y
		* mlx->texture[3].sz_line + 4 * mlx->bot.bot_tex_x + 1];
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x + 2] = mlx->texture[3].addr[mlx->bot.bot_tex_y
		* mlx->texture[3].sz_line + 4 * mlx->bot.bot_tex_x + 2];
}

void		ft_pixel_color(t_mlx *mlx, int x, int y, int v)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x] = mlx->texture[v].addr[mlx->t_y
		* mlx->texture[v].sz_line + 4 * mlx->t_x];
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x + 1] = mlx->texture[v].addr[mlx->t_y
		* mlx->texture[v].sz_line + 4 * mlx->t_x + 1];
	mlx->picture->addr[y * mlx->picture->sz_line + 4
		* x + 2] = mlx->texture[v].addr[mlx->t_y
		* mlx->texture[v].sz_line + 4 * mlx->t_x + 2];
}

void		ft_draw(t_mlx *mlx, int x)
{
	int y;
	int d;
	int v;

	y = 0;
	while (y < mlx->s_rend)
	{
		ft_calc_bot_top(mlx, WIN_HG - y);
		ft_pixel_color_top(mlx, x, y);
		y++;
	}
	while (y < mlx->e_rend)
	{
		d = y * 256 - WIN_HG * 128 + mlx->line_hg * 128;
		mlx->t_y = ((d * T_H) / mlx->line_hg) / 256;
		v = ft_side(mlx);
		ft_pixel_color(mlx, x, y, v);
		y++;
	}
	while (y < WIN_HG - 1)
	{
		ft_calc_bot_top(mlx, y);
		ft_pixel_color_bot(mlx, x, y);
		y++;
	}
}
