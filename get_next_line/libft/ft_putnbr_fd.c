/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:48:44 by rhusak            #+#    #+#             */
/*   Updated: 2017/11/24 18:35:50 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	int i;
	long	int z;
	int			r;

	r = 1;
	z = n;
	if (z < 0)
	{
		ft_putchar_fd('-', fd);
		z = -z;
	}
	i = z;
	while ((i /= 10) > 0)
		r *= 10;
	i = z;
	while (r)
	{
		ft_putchar_fd((i / r) + 48, fd);
		i %= r;
		r /= 10;
	}
}
