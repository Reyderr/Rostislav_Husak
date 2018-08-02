/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:11:16 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/02 13:21:47 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			ft_cleaning(t_list **lst, t_map **map)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->point);
		ft_memdel((void **)map);
	}
	return (0);
}

int			ft_line(int fd, t_list **lst, int nbr_p)
{
	t_list	*tmp;
	char	*line;
	int		gnl_ret;

	while ((gnl_ret = get_next_line(fd, &line)))
	{
		if (nbr_p == -1)
			nbr_p = (int)ft_countwords(line, ' ');
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (ft_strlen(line) == 1)
			return (0);
		if ((tmp) == NULL)
			return (ft_cleaning(lst, NULL));
		ft_lstadd(lst, tmp);
		if (nbr_p != (int)ft_countwords(line, ' ') || nbr_p == 0)
			return (ft_cleaning(lst, NULL));
		ft_strdel(&line);
	}
	if (nbr_p == -1 || gnl_ret == -1)
	{
		return (ft_cleaning(lst, NULL));
	}
	ft_reverse(lst);
	return (1);
}

void		ft_depth(t_map *map)
{
	int			min;
	int			max;
	t_point		p;
	t_point		cur;

	min = INT_MAX;
	max = INT_MIN;
	p.y = 0;
	while (p.y < map->hg)
	{
		p.x = 0;
		while (p.x < map->wd)
		{
			cur = *map->point[(int)p.y * map->wd + (int)p.x];
			if (cur.z < min)
				min = cur.z;
			if (cur.z > max)
				max = cur.z;
			p.x++;
		}
		p.y++;
	}
	map->d_min = min;
	map->d_max = max;
}

int			ft_fill_map(t_map **map, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < (*map)->hg)
	{
		x = 0;
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (ft_cleaning(&list, map));
		while (x < (*map)->wd)
		{
			(*map)->point[y * (*map)->wd + x] = ft_get_point(x, y, split[x]);
			x++;
		}
		ft_delete_split(&split);
		lst = lst->next;
		y++;
	}
	ft_depth(*map);
	ft_cleaning(&list, NULL);
	return (1);
}

int			ft_read_file(int fd, t_map **map)
{
	t_list	*lst;

	lst = NULL;
	if (!(ft_line(fd, &lst, -1)))
		return (0);
	*map = ft_get_map(ft_countwords(lst->content, ' '), ft_list_count(lst));
	if (*map == NULL)
		return (ft_cleaning(&lst, map));
	return (ft_fill_map(map, lst));
}
