/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:10:59 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/10 15:39:47 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	while (*str != '\0' && *str != (char)symbol)
		str++;
	if (*str != (char)symbol)
		return (NULL);
	else
		return ((char*)str);
}
