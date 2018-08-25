/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:58:14 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 17:02:47 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_delete(t_list **list, int fd, char **str)
{
	t_list	*p;
	t_gnl	*gnl;
	t_list	**tmp;

	tmp = list;
	while (*tmp)
	{
		gnl = (t_gnl *)((*tmp)->content);
		if (gnl->fd == fd)
			break ;
		*tmp = ((*tmp)->next);
	}
	if (*tmp)
	{
		p = (*tmp)->next;
		ft_strdel(&(gnl->buffer));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)tmp);
		*tmp = p;
	}
	ft_strdel(str);
}


char			*ft_connect(t_gnl *gnl)
{
	int i;

	i = 0;
	gnl->str = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buffer[gnl->i + i] == '\n')
		{
			gnl->str = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buffer, gnl->i - i, i - gnl->str));
}

int				ft_rd_buff(t_gnl *gnl, t_list **list, char **tmp, char **line)
{
	if (gnl->i == gnl->count)
	{
		gnl->count = read(gnl->fd, gnl->buffer, BUFF_SIZE);
		if (gnl->count == -1)
		{
			ft_delete(list, gnl->fd, tmp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->count == 0)
		{
			if (gnl->str == 0)
			{
				*line = *tmp;
				return (1);
			}
		}
	}
	return (0);
}

t_gnl			*ft_start(t_list **list, int fd)
{
	t_gnl	*gnl;
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		gnl = (t_gnl *)(temp->content);
		if (gnl->fd == fd)
			return (gnl);
		temp = temp->next;
	}
	gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	gnl->buffer = ft_strnew(BUFF_SIZE);
	gnl->count = BUFF_SIZE;
	gnl->i = BUFF_SIZE;
	gnl->fd = fd;
	gnl->str = 1;
	temp = ft_lstnew(gnl, sizeof(t_gnl));
	ft_memdel((void **)&gnl);
	ft_lstadd(list, temp);
	return ((t_gnl *)(temp->content));
}

int				get_next_line(int const fd, char **line, int ret)
{
	static t_list	*list;
	char			*tmp;
	t_gnl			*gnl;

	if (!line || BUFF_SIZE < 1 || !(*line = ft_strnew(0)) || read(fd, 0, 0))
		return (-1);
	ft_strdel(line);
	gnl = ft_start(&list, fd);
	tmp = ft_strnew(0);
	while (gnl->count > 0)
	{
		if ((ret = ft_rd_buff(gnl, &list, &tmp, line)) != 0)
			return (ret);
		while (gnl->i < gnl->count)
		{
			tmp = ft_association(tmp, ft_connect(gnl));
			if (gnl->str)
			{
				*line = tmp;
				return (1);
			}
		}
	}
	ft_delete(&list, fd, &tmp);
	return (0);
}
