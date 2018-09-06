/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:45:11 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/10 16:48:57 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	char *s1;

	s1 = NULL;
	while (*str != '\0')
	{
		if (*str == (char)symbol)
			s1 = (char*)str;
		str++;
	}
	if (*str == (char)symbol)
		return ((char*)str);
	else
		return (s1);
}
