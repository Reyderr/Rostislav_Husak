/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:42:24 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 15:46:51 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point		ft_project_point(t_point point, t_mlx *mlx)
{
	point.x -= (double)(mlx->map->wd - 1) / 2.0f;
	point.y -= (double)(mlx->map->hg - 1) / 2.0f;
	point.z -= (double)(mlx->map->d_min + mlx->map->d_max) / 2.0f;
	point = ft_rotate(point, mlx->eyes);
	point.x *= mlx->eyes->incr;
	point.y *= mlx->eyes->incr;
	point.x += mlx->eyes->o_x;
	point.y += mlx->eyes->o_y;
	return (point);
}

t_point		ft_shift(t_map *map, int x, int y)
{
	return (*map->point[y * map->wd + x]);
}

t_point		*ft_get_point(int x, int y, char *string)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	if (point == NULL)
		return (NULL);
	point->y = (double)y;
	point->z = (double)ft_atoi(string);
	point->x = (double)x;
	return (point);
}

t_map		*ft_get_map(int wd, int hg)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->point = ft_memalloc(sizeof(t_point *) * wd * hg);
	if (map->point == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	map->d_min = 0;
	map->wd = wd;
	map->hg = hg;
	map->d_max = 0;
	return (map);
}
