/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:35:18 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 13:58:58 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	ft_rotate(t_point point, t_eyes *eyes)
{
	t_point		rotate_point;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;

	rotate_x = point.x;
	rotate_z = point.z;
	rotate_point.x = cos(eyes->y) * rotate_x + sin(eyes->y) * rotate_z;
	rotate_point.z = -sin(eyes->y) * rotate_x + cos(eyes->y) * rotate_z;
	rotate_y = point.y;
	rotate_z = rotate_point.z;
	rotate_point.y = cos(eyes->x) * rotate_y - sin(eyes->x) * rotate_z;
	rotate_point.z = sin(eyes->x) * rotate_y + cos(eyes->x) * rotate_z;
	return (rotate_point);
}
