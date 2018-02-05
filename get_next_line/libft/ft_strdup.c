/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:05:27 by rhusak            #+#    #+#             */
/*   Updated: 2017/11/07 12:13:12 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	int		src_size;
	int		i;

	i = 0;
	src_size = 0;
	while (s1[src_size])
		src_size++;
	string = (char*)malloc(sizeof(*string) * (src_size + 1));
	if (string == NULL)
		return (NULL);
	while (i < src_size)
	{
		string[i] = s1[i];
		i++;
	}
	string[src_size] = '\0';
	return (string);
}
