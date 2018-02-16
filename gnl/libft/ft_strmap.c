/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:18:02 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/24 14:04:24 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strdup((char *)s);
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = (*f)(str[i]);
		i++;
	}
	return (str);
}
