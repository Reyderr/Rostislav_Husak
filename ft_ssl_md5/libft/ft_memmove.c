/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:31:22 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/24 14:14:06 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned	char	*s1;
	unsigned	char	*s2;

	s2 = (unsigned char*)dst;
	s1 = (unsigned char*)src;
	if (s2 <= s1 || s2 >= (s1 + len))
	{
		while (len--)
			*s2++ = *s1++;
	}
	else
	{
		s2 += len - 1;
		s1 += len - 1;
		while (len--)
			*s2-- = *s1--;
	}
	return (dst);
}
