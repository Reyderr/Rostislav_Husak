/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:35:18 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/01 16:28:35 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	ft_rotate(t_point p, t_cam *r)
{
	t_point		point;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	point.x = cos(r->y) * x + sin(r->y) * z;
	point.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = point.z;
	point.y = cos(r->x) * y - sin(r->x) * z;
	point.z = sin(r->x) * y + cos(r->x) * z;
	return (point);
}
