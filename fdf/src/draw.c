/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:26:23 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/01 17:08:07 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	int			ft_line_of_point(t_mlx *mlx, t_line *l, t_point *p1,
		t_point *p2)
{
	if (p1->x < 0 || p1->x >= WIN_WD || p1->y < 0 || p1->y >= WIN_HG
		|| p2->x < 0 || p2->x >= WIN_WD || p2->y < 0 || p2->y >= WIN_HG)
		return (1);
	ft_pixel_color(mlx, p1->x, p1->y);
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void				ft_line_create(t_mlx *mlx, t_point p1, t_point p2)
{
	t_line	line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	line.dx = (int)abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (ft_line_of_point(mlx, &line, &p1, &p2))
			break ;
}

void				ft_render(t_mlx *mlx)
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
			p = ft_project_point(ft_point_at(map, x, y), mlx);
			if (x + 1 < map->wd)
				ft_line_create(mlx, p, ft_project_point(ft_point_at(map,
				x + 1, y), mlx));
			if (y + 1 < map->hg)
				ft_line_create(mlx, p, ft_project_point(ft_point_at(map,
				x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}
