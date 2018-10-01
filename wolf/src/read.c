/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:01:26 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 18:05:28 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	ft_swap(t_map *m, int x, int y)
{
	if (m->sq[y][x] < 0 || m->sq[y][x] > 13)
		m->sq[y][x] = 1;
	if (m->sq[y][0] != 1)
		m->sq[y][0] = 1;
	if (m->sq[y][m->wd - 1] != 1)
		m->sq[y][m->wd - 1] = 1;
	if (m->sq[0][x] != 1)
		m->sq[0][x] = 1;
	if (m->sq[m->hg - 1][x] != 1)
		m->sq[m->hg - 1][x] = 1;
}

void	ft_check_p(t_map *m, int y, int x)
{
	if (m->sq[y][x] == 7)
	{
		m->port1_x = y;
		m->port1_y = x;
	}
	if (m->sq[y][x] == 8)
	{
		m->port2_x = y;
		m->port2_y = x;
	}
}

int		ft_man(t_map *m, char **split, int x, int y)
{
	m->sq[y][x] = ft_atoi(split[x]);
	ft_swap(m, x, y);
	if ((m->sq[y][x - 1] == 7 || m->sq[y][x - 1] == 8) && m->sq[y][x + 1])
		m->c = 1;
	if ((m->sq[y][x - 1] == 7 || m->sq[y][x - 1] == 8) && m->sq[y][x + 1])
		m->sq[y][x] = 0;
	if (ft_strchr(split[x], 's') && m->sq[y][x]
		!= m->sq[y][0] && m->sq[y][x] != m->sq[y][m->wd - 1]
		&& m->sq[y][x] != m->sq[0][x] && m->sq[y][x] != m->sq[m->hg - 1][x])
	{
		m->p_x = y + 0.5;
		m->p_y = x + 0.5;
	}
	ft_check_p(m, y, x);
	if (m->sq[y][x] < 0)
		return (0);
	return (1);
}
