/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:42:24 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/01 16:58:38 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point		ft_project_point(t_point p, t_mlx *mlx)
{
	p.x -= (double)(mlx->map->wd - 1) / 2.0f;
	p.y -= (double)(mlx->map->hg - 1) / 2.0f;
	p.z -= (double)(mlx->map->d_min + mlx->map->d_max) / 2.0f;
	p = ft_rotate(p, mlx->cam);
	p.x *= mlx->cam->scale;
	p.y *= mlx->cam->scale;
	p.x += mlx->cam->offsetx;
	p.y += mlx->cam->offsety;
	return (p);
}

t_point		ft_point_at(t_map *map, int x, int y)
{
	return (*map->point[y * map->wd + x]);
}

t_point		*ft_get_point(int x, int y, char *str)
{
	t_point	*p;

	p = ft_memalloc(sizeof(t_point));
	if (p == NULL)
		return (NULL);
	p->x = (double)x;
	p->y = (double)y;
	p->z = (double)ft_atoi(str);
	return (p);
}

t_map		*ft_get_map(int wd, int hg)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->wd = wd;
	map->hg = hg;
	map->d_min = 0;
	map->d_max = 0;
	map->point = ft_memalloc(sizeof(t_point *) * wd * hg);
	if (map->point == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}
