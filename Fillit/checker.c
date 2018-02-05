/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:29:25 by rhusak            #+#    #+#             */
/*   Updated: 2018/01/21 12:16:50 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_pos(char **map, t_tetra *tetra, int size)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetra->y[i] < size && tetra->x[i] < size
				&& map[tetra->y[i]][tetra->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_valid(char *stak, int k)
{
	int i;
	int dot;
	int slash;
	int grate;

	i = 0;
	slash = 0;
	dot = 0;
	grate = 0;
	while (i + k < 20 + k && stak[i + k] != '\0')
	{
		if (stak[i + k] == '#')
			grate++;
		if (stak[i + k] == '.')
			dot++;
		if (stak[i + k] == '\n')
			slash++;
		i++;
	}
	if (grate == 4 && dot == 12 && slash == 4)
		return (1);
	return (0);
}

int	ft_check_link(char *stak, int k)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (i + k < 20 + k)
	{
		if (stak[i + k] == '#')
		{
			if ((i + k + 1) < (20 + k) && stak[i + k + 1] == '#')
				n++;
			if ((i + k - 1) >= (0 + k) && stak[i + k - 1] == '#')
				n++;
			if ((i + k + 5) < (20 + k) && stak[i + k + 5] == '#')
				n++;
			if ((i + k - 5) >= (0 + k) && stak[i + k - 5] == '#')
				n++;
		}
		i++;
	}
	if (n == 6 || n == 8)
		return (1);
	return (0);
}

int	ft_check_str(char *stak)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (stak == NULL)
		return (0);
	while (stak[i + k] != '\0')
	{
		if (!(ft_check_link(stak, k) && ft_check_valid(stak, k)))
			return (0);
		i = 19;
		if (stak[i + k] == '\n' && stak[i + k + 1] == '\0')
			return (1);
		if (stak[i + k] == '\n' && stak[i + k + 1] == '\n'
			&& (stak[i + k + 2] == '.' || stak[i + k + 2] == '#'))
			k += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
