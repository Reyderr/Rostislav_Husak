/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:50:07 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/10 14:39:12 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)src)[i] == (unsigned char)c)
		{
			return ((unsigned char*)src + i);
		}
		i++;
	}
	return (NULL);
}
