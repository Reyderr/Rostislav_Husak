/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:22:17 by rhusak            #+#    #+#             */
/*   Updated: 2018/01/17 12:26:51 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void		ft_pos_xy(t_tetra **tetra, int x, int y)
{
	int	pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 12;
	pos_y = 12;
	while (i < 4)
	{
		if ((*tetra)->x[i] < pos_x)
			pos_x = (*tetra)->x[i];
		if ((*tetra)->y[i] < pos_y)
			pos_y = (*tetra)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetra)->x[i] = (*tetra)->x[i] - pos_x + x;
		(*tetra)->y[i] = (*tetra)->y[i] - pos_y + y;
		i--;
	}
}

char		**ft_recursive(char **tetra_map, t_tetra *tetra, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetra->next == NULL)
		return (tetra_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_pos_xy(&tetra, x, y);
			if (ft_check_pos(tetra_map, tetra, size))
				map = ft_recursive(ft_in_tetra(tetra_map, tetra, size),
						tetra->next, size);
			if (map)
				return (map);
			tetra_map = ft_del_tetra(tetra_map, tetra, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		ft_solution(t_tetra *tetra)
{
	char	**result;
	char	**tetra_map;
	int		size;

	size = 2;
	tetra_map = NULL;
	tetra_map = ft_new_map(tetra_map, size);
	result = NULL;
	while (!(result = ft_recursive(tetra_map, tetra, size)))
	{
		size++;
		ft_memdel((void **)tetra_map);
		tetra_map = ft_new_map(tetra_map, size);
	}
	ft_print_map(result);
}
