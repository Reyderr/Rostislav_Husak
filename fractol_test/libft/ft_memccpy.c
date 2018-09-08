/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:10:30 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/10 16:48:19 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *)s1;
	src = (char *)s2;
	while (n > 0)
	{
		*dest++ = *src++;
		if (*(src - 1) == (char)c)
		{
			return (dest);
		}
		n--;
	}
	return (NULL);
}
