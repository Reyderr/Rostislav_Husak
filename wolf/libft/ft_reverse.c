/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:36:04 by rhusak            #+#    #+#             */
/*   Updated: 2018/07/21 14:28:49 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_reverse(t_list **alst)
{
	t_list	*a;
	t_list	*b;
	t_list	*next;

	a = NULL;
	b = *alst;
	while (b != NULL)
	{
		next = b->next;
		b->next = a;
		a = b;
		b = next;
	}
	*alst = a;
}
