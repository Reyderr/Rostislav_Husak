/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:06:50 by rhusak            #+#    #+#             */
/*   Updated: 2018/07/21 14:27:29 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_delete_split(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*split)[i];
	}
	ft_memdel((void **)split);
	return (0);
}
