/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_association.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:59:36 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 11:57:42 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_association(char *a, char *b)
{
	char	*str;

	str = ft_strjoin(a, b);
	ft_strdel(&a);
	ft_strdel(&b);
	return (str);
}
