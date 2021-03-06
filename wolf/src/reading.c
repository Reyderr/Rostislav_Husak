/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:00:42 by rhusak            #+#    #+#             */
/*   Updated: 2018/10/01 14:48:34 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		*cleanup(t_list *lst, t_map *m)
{
	t_list	*next;
	int		i;

	i = 0;
	while (lst)
	{
		next = lst->next;
		ft_memdel(&lst->content);
		ft_memdel((void **)&lst);
		lst = next;
	}
	if (m)
	{
		if (m->sq)
			while (i < m->hg)
			{
				if (m->sq + i)
					ft_memdel((void **)(m->sq + i));
				i++;
			}
		ft_memdel((void **)&m);
	}
	return (NULL);
}

t_list		*get_lines(int fd)
{
	static int	expected = -1;
	t_list		*lst;
	t_list		*temp;
	char		*line;
	int			ret;

	lst = NULL;
	while ((ret = get_next_line(fd, &line, 0)))
	{
		if (expected == -1)
			expected = ft_countwords(line, ' ');
		if (expected == 0 || ft_countwords(line, ' ') != expected ||
			(temp = ft_lstnew(line, ft_strlen(line) + sizeof(char))) == NULL)
			return (cleanup(lst, NULL));
		ft_strdel(&line);
		ft_lstadd(&lst, temp);
	}
	if (ret == -1)
		return (cleanup(lst, NULL));
	ft_reverse(&lst);
	return (lst);
}

t_map		*populate_map(t_map *m, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < m->hg)
	{
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (cleanup(list, m));
		x = 0;
		while (x < m->wd)
		{
			if (!ft_man(m, split, x, y))
				return (NULL);
			x++;
		}
		ft_delete_split(&split);
		lst = lst->next;
		y++;
	}
	cleanup(list, NULL);
	return (m);
}

t_map		*new_map(int w, int h)
{
	t_map	*m;
	int		i;

	if ((m = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	m->wd = w;
	m->hg = h;
	if ((m->sq = (int **)ft_memalloc(sizeof(int *) * (w * h))) == NULL)
	{
		ft_memdel((void **)&m);
		return (NULL);
	}
	i = 0;
	while (i < h)
	{
		if ((m->sq[i] = (int *)ft_memalloc(sizeof(int) * (w * h))) == NULL)
		{
			while (i > 0)
				ft_memdel((void **)(m->sq + --i));
			ft_memdel((void **)&m);
			return (NULL);
		}
		i++;
	}
	return (m);
}

t_map		*ft_read_file(char *file)
{
	t_list		*lst;
	t_map		*map;
	int			fd;
	int			w;
	int			h;

	if ((fd = open(file, O_RDONLY)) == -1 ||
			(lst = get_lines(fd)) == NULL)
		return (NULL);
	w = ft_countwords((char *)lst->content, ' ');
	h = ft_list_count(lst);
	if (w < 3 || h < 3)
		return (cleanup(lst, NULL));
	map = new_map(w, h);
	if (map == NULL)
		return (cleanup(lst, NULL));
	if (populate_map(map, lst) == NULL)
		return (NULL);
	if (!map->p_y || !map->p_x)
	{
		ft_strcol("Bad starting position\n", PURPLE);
		exit(EXIT_SUCCESS);
	}
	return (map);
}
