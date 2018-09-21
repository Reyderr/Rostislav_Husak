/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:28:12 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/18 17:08:55 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *str, char del)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == del)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != del)
			i++;
		result++;
		while (str[i] && str[i] == del)
			i++;
	}
	return (result);
}
