/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:53:26 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/30 07:53:27 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_initialaze(t_hesh *hesh)
{
	hesh->head.heshes0 = 0x67452301;
	hesh->head.heshes1 = 0xefcdab89;
	hesh->head.heshes2 = 0x98badcfe;
	hesh->head.heshes3 = 0x10325476;
}

void		ft_spo(t_hesh *hesh, size_t len)
{
	*(uint32_t*)(hesh->input_line + len) = 0x80;
	*(uint32_t*)(hesh->input_line + hesh->ini.next_l) = (uint32_t)(8 * len);
	hesh->ini.bias = 0;
}

void		ft_yop(t_hesh *hesh)
{
	hesh->dls.torl = (uint32_t *)(hesh->input_line + hesh->ini.bias);
	hesh->block.a = hesh->head.heshes0;
	hesh->block.b = hesh->head.heshes1;
	hesh->block.c = hesh->head.heshes2;
	hesh->block.d = hesh->head.heshes3;
}

char		*ft_zero_inp(char *line)
{
	int num;

	num = ft_strlen(line);
	while (num < 8)
	{
		ft_putchar('0');
		num++;
	}
	return (line);
}
