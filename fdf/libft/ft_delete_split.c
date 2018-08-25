/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:06:50 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 12:02:44 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_delete_split(char ***spliter)
{
	char	**str;
	int		i;

	i = 0;
	str = *spliter;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*spliter)[i];
	}
	ft_memdel((void **)spliter);
	return (0);
}
