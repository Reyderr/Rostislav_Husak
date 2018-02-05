/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:28:54 by rhusak            #+#    #+#             */
/*   Updated: 2018/01/21 12:23:01 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_numb_tetra(char *input_map)
{
	int i;
	int rezult;

	i = 0;
	rezult = 0;
	while (input_map[i] != '\0')
	{
		if (input_map[i] == '#')
			rezult++;
		i++;
	}
	if (rezult / 4 > 26)
		return (0);
	return (rezult / 4);
}

void	ft_position_tetra(t_tetra **tetra, char *input_map)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (input_map[i] != '\0')
	{
		if (input_map[i] == '#')
		{
			(*tetra)->x[num] = i % 5;
			(*tetra)->y[num] = i / 5;
			num++;
		}
		i++;
	}
}

t_tetra	*ft_born_tetra(char *input_map)
{
	int		next_tetra;
	int		n_tetra;
	char	c;
	t_tetra	*tetra;
	t_tetra	*output;

	next_tetra = 0;
	c = 'A';
	n_tetra = ft_numb_tetra(input_map);
	if (!(output = (t_tetra *)malloc(sizeof(t_tetra))))
		return (NULL);
	tetra = output;
	while (n_tetra > 0)
	{
		tetra->c = c;
		ft_position_tetra(&tetra, ft_strsub(input_map, 0 + next_tetra, 20));
		if (!(tetra->next = (t_tetra *)malloc(sizeof(t_tetra))))
			return (NULL);
		tetra = tetra->next;
		next_tetra += 21;
		n_tetra--;
		c++;
	}
	tetra->next = NULL;
	return (output);
}

char	*ft_read_map(int fd)
{
	char	s;
	char	*map;
	int		i;
	int		f;

	i = 0;
	map = NULL;
	f = read(fd, &s, 1);
	if (f < 0)
		return (NULL);
	if (f == 1)
	{
		map = (char *)malloc(sizeof(char) * 546);
		while (f != '\0')
		{
			if (i > 546)
				return (0);
			map[i++] = s;
			f = read(fd, &s, 1);
		}
		map[i] = '\0';
	}
	return (map);
}
