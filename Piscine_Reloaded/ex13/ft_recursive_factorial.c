/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:07:58 by rhusak            #+#    #+#             */
/*   Updated: 2017/10/31 14:08:57 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int f;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		f = ft_recursive_factorial(nb - 1);
		if ((nb * f) / nb != f)
			return (0);
		return (nb * f);
	}
}
