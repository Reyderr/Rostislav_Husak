/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:04:50 by rhusak            #+#    #+#             */
/*   Updated: 2018/01/21 12:13:24 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		ft_putendl("error");
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

char	**ft_new_map(char **map, int size)
{
	int	y;
	int	x;

	y = 0;
	map = (char**)malloc(sizeof(char*) * size + 1);
	if (map == NULL)
		return (NULL);
	while (y < size)
	{
		map[y] = (char*)malloc(sizeof(char) * size + 1);
		if (map[y] == NULL)
			return (NULL);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = 0;
	return (map);
}

char	**ft_del_tetra(char **map, t_tetra *tetra, int size)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetra->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char	**ft_in_tetra(char **map, t_tetra *tetra, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetra->y[i] == y && tetra->x[i] == x)
			{
				map[y][x] = tetra->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}
