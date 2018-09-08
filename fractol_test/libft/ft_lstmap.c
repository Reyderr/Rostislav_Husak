/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 11:53:32 by rhusak            #+#    #+#             */
/*   Updated: 2017/12/25 11:53:38 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lst1;
	t_list		*lst2;

	lst2 = (t_list *)malloc(sizeof(t_list));
	lst1 = lst2;
	while (lst != NULL)
	{
		if ((lst1->next = f(lst)) == NULL)
			return (NULL);
		lst = lst->next;
		lst1 = lst1->next;
	}
	return (lst2->next);
}
