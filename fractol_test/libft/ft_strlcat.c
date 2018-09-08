/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:34:13 by rhusak            #+#    #+#             */
/*   Updated: 2017/11/24 18:39:30 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	char	*d;
	char	*text;

	d = (char *)ft_memchr(dst, '\0', dstsize);
	if (d == NULL)
		return (dstsize + ft_strlen((char *)src));
	text = (char *)src;
	len = (size_t)(d - dst) + ft_strlen(text);
	while ((size_t)(d - dst) < dstsize - 1 && *text != '\0')
	{
		*d = *text;
		d++;
		text++;
	}
	*d = '\0';
	return (len);
}
