/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:28:02 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:28:05 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	ft_rev(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
		((n & 0xff00) << 8) | (n << 24));
}

void		ft_js_qs(int fd, t_hesh *hesh)
{
	char	*poi;
	char	b[2];

	poi = ft_strdup("");
	b[1] = '\0';
	while ((read(fd, b, 1)) > 0)
		poi = ft_strjoin(poi, b);
	hesh->input_l = poi;
}

void		ft_a1(t_hesh *hesh, int u)
{
	hesh->bl.a1 = RIGHTROTATION(hesh->dls.torl[u - 2], 17) ^
	RIGHTROTATION(hesh->dls.torl[u - 2], 19)
	^ (hesh->dls.torl[u - 2] >> 10);
}
