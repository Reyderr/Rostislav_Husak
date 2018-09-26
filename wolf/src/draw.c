/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:06:24 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/26 15:46:19 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_calc_bot_top(t_mlx *mlx, int y)
{
	mlx->bot.way = WIN_HG / (2. * y - WIN_HG);
	mlx->bot.wt = (mlx->bot.way - mlx->bot.p_way) / (mlx->bot.w_w - mlx->bot.p_way);
	mlx->bot.c_bot_x = mlx->bot.wt * mlx->bot.b_x + (1.0 - mlx->bot.wt) * mlx->map->p_x;
	mlx->bot.c_bot_y = mlx->bot.wt * mlx->bot.b_y + (1.0 - mlx->bot.wt) * mlx->map->p_y;
	mlx->bot.bot_tex_x = (int)(mlx->bot.c_bot_x * T_W) % T_W;
	 mlx->bot.bot_tex_y = (int)(mlx->bot.c_bot_y * T_H) % T_H;
}

void	ft_pixel_color_bot(t_mlx *mlx, int x, int y)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = mlx->texture[4].addr[ mlx->bot.bot_tex_y * mlx->texture[4].sz_line + 4 * mlx->bot.bot_tex_x] ;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = mlx->texture[4].addr[ mlx->bot.bot_tex_y * mlx->texture[4].sz_line + 4 * mlx->bot.bot_tex_x + 1];
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = mlx->texture[4].addr[ mlx->bot.bot_tex_y * mlx->texture[4].sz_line + 4 * mlx->bot.bot_tex_x + 2];
}

void	ft_pixel_color_top(t_mlx *mlx, int x, int y)
{
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = mlx->texture[3].addr[ mlx->bot.bot_tex_y * mlx->texture[3].sz_line + 4 * mlx->bot.bot_tex_x] ;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = mlx->texture[3].addr[ mlx->bot.bot_tex_y * mlx->texture[3].sz_line + 4 * mlx->bot.bot_tex_x + 1];
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = mlx->texture[3].addr[ mlx->bot.bot_tex_y * mlx->texture[3].sz_line + 4 * mlx->bot.bot_tex_x + 2];
}

int	ft_side(t_mlx *mlx)
{
	if(mlx->wall == 0)
	{
		if ((mlx->iter_x == -1 && mlx->iter_y == 1) || (mlx->iter_x == -1 && mlx->iter_y == -1) )
		{
			return(1);
		}
		if((mlx->iter_x == 1 && mlx->iter_y == -1) || (mlx->iter_x == 1 && mlx->iter_y == 1) )
			return(2);
	}
 	if ((mlx->iter_x == 	-1 && mlx->iter_y == 1) || (mlx->iter_x == 1 && mlx->iter_y == 1) )
			return(3);
	else 
			return(mlx->num);
}

void	ft_pixel_color(t_mlx *mlx, int x, int y, int v)
{	
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x] = mlx->texture[v].addr[mlx->t_y * mlx->texture[v].sz_line + 4 * mlx->t_x] ;
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 1] = mlx->texture[v].addr[mlx->t_y * mlx->texture[v].sz_line + 4 * mlx->t_x + 1];
	mlx->picture->addr[y * mlx->picture->sz_line + 4 * x + 2] = mlx->texture[v].addr[mlx->t_y * mlx->texture[v].sz_line + 4 * mlx->t_x + 2];
}

void	ft_draw(t_mlx *mlx, int x)
{
	int y;
	int d;
	int v;

	y = 0;
	while (y <  mlx->s_rend)
	{
		ft_calc_bot_top(mlx, WIN_HG - y);
		ft_pixel_color_top(mlx, x, y);
		y++;
	}
	while(y < mlx->e_rend)
	{
		d  = y * 256 - WIN_HG * 128 + mlx->line_hg * 128;
		mlx->t_y = ((d * T_H) / mlx->line_hg) / 256;
		v = ft_side(mlx);
		ft_pixel_color(mlx, x, y, v);
		y++;
	}
	while(y < WIN_HG)
	{
		ft_calc_bot_top(mlx, y);
		ft_pixel_color_bot(mlx, x, y);
		y++;
	}
}