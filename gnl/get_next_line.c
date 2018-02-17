/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:06:27 by rhusak            #+#    #+#             */
/*   Updated: 2018/02/17 11:31:06 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*check_old_heap(const int fd, t_list **llst)
{
	t_list		*elm;
	t_gnl		heap;

	elm = *llst;
	while (elm)
	{
		if (((t_gnl *)(elm->content))->fd == fd)
			return (elm->content);
		elm = elm->next;
	}
	heap.fd = fd;
	if (!(heap.str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(elm = ft_lstnew(&heap, sizeof(t_gnl))))
		return (NULL);
	ft_lstadd(llst, elm);
	return ((*llst)->content);
}

static int			read_line(t_gnl *heap)
{
	int			count;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	count = 1;
	while (count > 0 && !ft_strchr(heap->str, '\n'))
	{
		if ((count = read(heap->fd, &buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[count] = 0;
		tmp = heap->str;
		heap->str = ft_strjoin(heap->str, buff);
		free(tmp);
		ft_memset(buff, 0, count);
	}
	return (count);
}

static char			*update_line(char *str)
{
	char	*pos;

	if (!(pos = ft_strchr(str, '\n')))
		return (ft_strdup(str));
	return (ft_strsub(str, 0, pos - str));
}

static void			move_str(char **str)
{
	char *tmp;
	char *pos;

	tmp = *str;
	if (!(pos = ft_strchr(tmp, '\n')))
		*str = ft_strnew(0);
	else
		*str = ft_strdup(pos + 1);
	free(tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_gnl			*heap;
	char			*tmp;
	int				count;

	if (!line || fd < 0)
		return (-1);
	heap = check_old_heap(fd, &lst);
	if (((count = read_line(heap)) == -1) || heap == NULL)
		return (-1);
	*line = update_line(heap->str);
	tmp = heap->str;
	move_str(&(heap->str));
	if (!**line && !count)
		return (0);
	else
		return (1);
}
