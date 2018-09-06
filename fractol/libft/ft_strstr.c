/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:39:05 by rhusak            #+#    #+#             */
/*   Updated: 2017/11/10 13:19:54 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int g;
	int count;

	count = 0;
	g = 0;
	i = 0;
	while (needle[count])
		count++;
	if (count == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[g] == haystack[i + g])
		{
			if (g == count - 1)
				return ((char *)haystack + i);
			g++;
		}
		g = 0;
		i++;
	}
	return (0);
}
