/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:10:33 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/02 17:37:50 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*g;
	char	*s;
	size_t	i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	g = (char *)dst;
	s = (char *)src;
	while (--n)
	{
		g[i] = s[i];
		i++;
	}
	g[i] = s[i];
	return (g);
}
