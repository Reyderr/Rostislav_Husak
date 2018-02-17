/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:07:21 by rhusak            #+#    #+#             */
/*   Updated: 2018/02/16 10:07:25 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct				s_gnl
{
	int						fd;
	char					*str;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif
