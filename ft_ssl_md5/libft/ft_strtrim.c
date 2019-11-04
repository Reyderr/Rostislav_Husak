/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:17:56 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/25 16:06:36 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_white(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t	b;
	size_t	e;
	char	*str;

	if (!s)
		return (0);
	b = 0;
	while (ft_white(s[b]))
		b++;
	e = ft_strlen(s) - 1;
	while (e > b && ft_white(s[e]))
		e--;
	str = ft_strsub(s, b, e - b + 1);
	return (str);
}
