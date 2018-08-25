/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:26:23 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 15:48:19 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int					ft_beam_of_point(t_mlx *mlx, t_beam *beam, t_point *f_point,
		t_point *s_point)
{
	if (f_point->x < 0 || f_point->x >= WIN_WD || f_point->y < 0
		|| f_point->y >= WIN_HG || s_point->x < 0 || s_point->x >= WIN_WD
		|| s_point->y < 0 || s_point->y >= WIN_HG)
		return (1);
	ft_pixel_color(mlx, f_point->x, f_point->y);
	beam->s_bias = beam->f_bias;
	if (beam->s_bias < beam->dy)
	{
		beam->f_bias += beam->dx;
		f_point->y += beam->check_y;
	}
	if (beam->s_bias > -beam->dx)
	{
		beam->f_bias -= beam->dy;
		f_point->x += beam->check_x;
	}
	return (0);
}

void				ft_beam_create(t_mlx *mlx, t_point f_point, t_point s_point)
{
	t_beam	beam;

	beam.stop = s_point;
	beam.start = f_point;
	beam.dx = (int)abs((int)s_point.x - (int)f_point.x);
	if (f_point.x < s_point.x)
		beam.check_x = 1;
	else
		beam.check_x = -1;
	beam.dy = (int)abs((int)s_point.y - (int)f_point.y);
	if (f_point.y < s_point.y)
		beam.check_y = 1;
	else
		beam.check_y = -1;
	if (beam.dx > beam.dy)
		beam.f_bias = beam.dx / 2;
	else
		beam.f_bias = -beam.dy / 2;
	while (((int)f_point.x != (int)s_point.x
		|| (int)f_point.y != (int)s_point.y))
		if (ft_beam_of_point(mlx, &beam, &f_point, &s_point))
			break ;
}

void				ft_processing(t_mlx *mlx)
{
	int			x;
	int			y;
	t_point		p;
	t_map		*map;

	map = mlx->map;
	ft_clear_picture(mlx->picture);
	x = 0;
	while (x < map->wd)
	{
		y = 0;
		while (y < map->hg)
		{
			p = ft_project_point(ft_shift(map, x, y), mlx);
			if (x + 1 < map->wd)
				ft_beam_create(mlx, p, ft_project_point(ft_shift(map,
				x + 1, y), mlx));
			if (y + 1 < map->hg)
				ft_beam_create(mlx, p, ft_project_point(ft_shift(map,
				x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}
