/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:58:25 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 12:15:33 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

# include <unistd.h>
# include "libft.h"

typedef struct	s_gnl
{
	int			str;
	char		*buffer;
	int			count;
	int			i;
	int			fd;
}				t_gnl;

int				get_next_line(int const fd, char **line, int ret);

#endif
