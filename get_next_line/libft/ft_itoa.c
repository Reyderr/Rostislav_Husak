/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:49:17 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/24 14:12:52 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned	int	ft_size(int n)
{
	int size;

	size = 0;
	if (n < 0)
		size = 1;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return ((unsigned int)size);
}

char					*ft_itoa(int n)
{
	char			*str;
	unsigned	int	size;
	long			number;

	number = n;
	size = ft_size(n);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	if (number == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while ((number % 10) > 0 || (number / 10 != 0))
	{
		str[size--] = '0' + (number % 10);
		number = number / 10;
	}
	return (str);
}
