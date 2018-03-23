/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:47:29 by rhusak            #+#    #+#             */
/*   Updated: 2017/10/31 12:51:51 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*mass;
	int		i;

	i = 0;
	if (min >= max)
		return (0);
	mass = (int*)malloc(sizeof(*mass) * (max - min));
	while (min < max)
	{
		mass[i] = min;
		min++;
		i++;
	}
	return (mass);
}
