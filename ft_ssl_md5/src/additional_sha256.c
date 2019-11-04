/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sha256.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:09:16 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/30 08:09:17 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_ini(t_hesh *hesh)
{
	hesh->head.heshes2 = 0x3c6ef372;
	hesh->head.heshes3 = 0xa54ff53a;
	hesh->sha_h.hesh2 = 0x1f83d9ab;
	hesh->sha_h.hesh0 = 0x510e527f;
	hesh->head.heshes0 = 0x6a09e667;
	hesh->head.heshes1 = 0xbb67ae85;
	hesh->sha_h.hesh1 = 0x9b05688c;
	hesh->sha_h.hesh3 = 0x5be0cd19;
}

void		ft_bs_ini(t_hesh *hesh)
{
	hesh->bl.f6 = hesh->bl.d4 + hesh->bl.e5;
	hesh->block.h = hesh->block.g;
	hesh->block.g = hesh->block.f;
	hesh->block.f = hesh->block.e;
	hesh->block.e = hesh->block.d + hesh->bl.c3;
	hesh->block.d = hesh->block.c;
	hesh->block.c = hesh->block.b;
	hesh->block.b = hesh->block.a;
	hesh->block.a = hesh->bl.c3 + hesh->bl.f6;
}

void		ft_compreh(t_hesh *hesh)
{
	hesh->head.heshes0 += hesh->block.a;
	hesh->head.heshes1 += hesh->block.b;
	hesh->head.heshes2 += hesh->block.c;
	hesh->head.heshes3 += hesh->block.d;
	hesh->sha_h.hesh0 += hesh->block.e;
	hesh->sha_h.hesh1 += hesh->block.f;
	hesh->sha_h.hesh2 += hesh->block.g;
	hesh->sha_h.hesh3 += hesh->block.h;
}

void		ft_ebro(t_hesh *hesh, char *s)
{
	ft_bzero(hesh->dls.sys32, OCT * hesh->ini.bias * 4);
	ft_strcpy((char *)hesh->dls.sys32, s);
	((char*)hesh->dls.sys32)[ft_strlen(s)] = 0x80;
}

void		ft_rmbo(t_hesh *hesh, int num)
{
	int z;
	int q;

	q = hesh->ini.bias * BITOVOCH;
	z = (hesh->ini.bias * OCT) - 1;
	while (num < z)
	{
		hesh->dls.sys32[num] = ft_rev(hesh->dls.sys32[num]);
		num++;
	}
	hesh->dls.sys32[((q - MIN_BIT) / 32) + 1] = hesh->ini.next_l;
}
