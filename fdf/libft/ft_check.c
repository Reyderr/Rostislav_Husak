/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:06:22 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 11:59:30 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_check(double numb, double one, double two)
{
	if (numb == two)
		return (1.0);
	if (numb == one)
		return (0.0);
	return ((numb - one) / (two - one));
}
