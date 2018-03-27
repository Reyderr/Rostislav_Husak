/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:30:03 by rhusak            #+#    #+#             */
/*   Updated: 2018/03/25 14:01:34 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_size(int num)
{
	int size;

	size = 0;
	if (num < 0)
		size = 1;
	while (num / 10)
	{
		size++;
		num = num / 10;
	}
	return (size);
}


char *ft_strnew(int s)
{
	char *str1;
	int i;

	i = 0;
	str1 = (char *)malloc(sizeof(*str1) * (s + 1));
	if(str1 == NULL)
		return (NULL);
	while (i <= s)
	{
		str1[i] = 0;
		i++;
	}
	return(str1);
}


char *ft_itoa(int nbr)
{
	long number;
	int size;
	char *str;

	number = nbr;
	size = ft_size(number);
	str = ft_strnew(size);
	if (!str)
		return(NULL);
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
