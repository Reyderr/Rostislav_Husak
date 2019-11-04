/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:28:09 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/24 14:15:00 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_size(const char *s, char c)
{
	if (*s && *s != c)
		return (ft_size(s + 1, c) + 1);
	return (0);
}

static	int		ft_word(const char *s, char c)
{
	if (!*s)
		return (1);
	if (*s != c)
		return (ft_word(s + 1, c));
	while (*s && *s == c)
		s++;
	return (ft_word(s, c) + 1);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		size;
	int		index;

	if (!s)
		return (NULL);
	size = ft_word(s, c);
	tab = (char**)malloc(sizeof(char*) * size + 1);
	if (!tab)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			size = ft_size(s, c);
			tab[index++] = ft_strsub(s, 0, size);
			s += size;
		}
		else
			++s;
	}
	tab[index] = NULL;
	return (tab);
}
