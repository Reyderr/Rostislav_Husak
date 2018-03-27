/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:31:05 by rhusak            #+#    #+#             */
/*   Updated: 2018/03/25 14:36:09 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	(*f)(begin_list->data);
	if (begin_list->next)
		ft_list_foreach(begin_list->next, f);
}
