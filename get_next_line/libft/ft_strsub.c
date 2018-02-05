/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:16:56 by rhusak            #+#    #+#             */
/*   Updated: 2017/11/20 16:16:24 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	z;

	i = start;
	z = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (z < len)
	{
		str[z] = s[i];
		z++;
		i++;
	}
	str[z] = '\0';
	return (str);
}
