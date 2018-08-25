/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:11:16 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 16:02:05 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			ft_cleaning(t_list **list, t_map **map)
{
	t_list	*next;

	while (*list)
	{
		next = (*list)->next;
		ft_memdel(&(*list)->content);
		ft_memdel((void **)list);
		*list = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->point);
		ft_memdel((void **)map);
	}
	return (0);
}

int			ft_line(int fd, t_list **list, int points)
{
	t_list	*temporary;
	char	*line;
	int		bb;

	while ((bb = get_next_line(fd, &line, 0)))
	{
		if (points == -1)
			points = (int)ft_countwords(line, ' ');
		temporary = ft_lstnew(line, ft_strlen(line) + 1);
		if (ft_strlen(line) == 1)
			return (0);
		if ((temporary) == NULL)
			return (ft_cleaning(list, NULL));
		ft_lstadd(list, temporary);
		if (points != (int)ft_countwords(line, ' ') || points == 0)
			return (ft_cleaning(list, NULL));
		ft_strdel(&line);
	}
	if (points == -1 || bb == -1)
		return (ft_cleaning(list, NULL));
	ft_reverse(list);
	return (1);
}

void		ft_prof(t_map *map)
{
	t_point		actual;
	int			min;
	int			max;
	t_point		point;

	point.y = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (point.y < map->hg)
	{
		point.x = 0;
		while (point.x < map->wd)
		{
			actual = *map->point[(int)point.y * map->wd + (int)point.x];
			if (actual.z < min)
				min = actual.z;
			if (actual.z > max)
				max = actual.z;
			point.x++;
		}
		point.y++;
	}
	map->d_min = min;
	map->d_max = max;
}

int			ft_fill_map(t_map **map, t_list *list)
{
	t_list	*lst;
	char	**splited;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < (*map)->hg)
	{
		x = 0;
		if ((splited = ft_strsplit(lst->content, ' ')) == NULL)
			return (ft_cleaning(&lst, map));
		while (x < (*map)->wd)
		{
			(*map)->point[y * (*map)->wd + x] = ft_get_point(x, y, splited[x]);
			x++;
		}
		ft_delete_split(&splited);
		lst = lst->next;
		y++;
	}
	ft_prof(*map);
	ft_cleaning(&list, NULL);
	return (1);
}

int			ft_read_file(int fd, t_map **map)
{
	t_list	*list;

	list = NULL;
	if (!(ft_line(fd, &list, -1)))
		return (0);
	*map = ft_get_map(ft_countwords(list->content, ' '), ft_list_count(list));
	if (*map == NULL)
		return (ft_cleaning(&list, map));
	return (ft_fill_map(map, list));
}
