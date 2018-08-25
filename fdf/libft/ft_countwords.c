/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:28:12 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 12:00:17 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char *str, char d)
{
	size_t result;
	size_t i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == d)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != d)
			i++;
		result++;
		while (str[i] && str[i] == d)
			i++;
	}
	return (result);
}
