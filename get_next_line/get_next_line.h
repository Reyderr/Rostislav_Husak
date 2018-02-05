/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:55:16 by rhusak            #+#    #+#             */
/*   Updated: 2018/02/05 14:55:32 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_llst
{
	void			*content;
	size_t			content_size;
	struct s_llst	*next;
	int				fd;
}					t_gnl;

int					get_next_line(int const fd, char **line);
int					gnl_build(int fd, char *buf, t_gnl **head);
t_gnl				*gnl_search(int fd, t_gnl **head);
char				*gnl_trim(int fd, t_gnl **head);

#endif
