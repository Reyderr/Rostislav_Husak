/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:29:45 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:29:49 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const uint32_t g_k2[] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

int			ft_st_vr_sha256(char *init_mg, size_t len, t_hesh *hesh)
{
	int		i;
	int		sum;

	ft_ini(hesh);
	hesh->ini.next_l = len * 8;
	sum = 1 + ((hesh->ini.next_l + OCT + MIN_BIT) / BITOVOCH);
	hesh->ini.bias = sum;
	if (!(hesh->dls.sys32 = malloc(OCT * hesh->ini.bias * 4)))
		return (-1);
	ft_ebro(hesh, init_mg);
	i = 0;
	ft_rmbo(hesh, i);
	return (0);
}

void		ft_d4(t_hesh *hesh, int u)
{
	int z;
	int i;

	z = 0;
	i = 0;
	while (z < 20)
	{
		z++;
		i++;
	}
	hesh->bl.d4 = RIGHTROTATION(hesh->dls.torl[u - 15], 7) ^
					RIGHTROTATION(hesh->dls.torl[u - 15], 18)
					^ (hesh->dls.torl[u - 15] >> 3);
}

void		ft_arshed(int i, t_hesh *hesh)
{
	int j;

	hesh->dls.torl = malloc(BITOVOCH);
	ft_bzero(hesh->dls.torl, BITOVOCH);
	ft_memcpy(hesh->dls.torl, &hesh->dls.sys32[i * OCT], OCT * 32);
	j = OCT;
	while (j < MIN_BIT)
	{
		ft_d4(hesh, j);
		ft_a1(hesh, j);
		hesh->dls.torl[j] = hesh->dls.torl[j
			- OCT] + hesh->bl.d4 + hesh->dls.torl[j - 7] + hesh->bl.a1;
		j++;
	}
	ft_de_ini(hesh);
}

void		ft_calc_sha256(int j, t_hesh *hesh)
{
	hesh->bl.a1 = RIGHTROTATION(hesh->block.e, 6)
	^ RIGHTROTATION(hesh->block.e, 11) ^ RIGHTROTATION(hesh->block.e, 25);
	hesh->bl.b2 = (hesh->block.e & hesh->block.f)
	^ ((~hesh->block.e) & hesh->block.g);
	hesh->bl.c3 = hesh->block.h + hesh->bl.a1 + hesh->bl.b2
	+ g_k2[j] + hesh->dls.torl[j];
	hesh->bl.d4 = RIGHTROTATION(hesh->block.a, 2)
	^ RIGHTROTATION(hesh->block.a, 13) ^ RIGHTROTATION(hesh->block.a, 22);
	hesh->bl.e5 = (hesh->block.a & hesh->block.b)
	^ (hesh->block.a & hesh->block.c) ^ (hesh->block.b & hesh->block.c);
	ft_bs_ini(hesh);
}

int			ft_st_sha256(char *init_mg, size_t len, t_hesh *hesh)
{
	int i;
	int j;

	ft_st_vr_sha256(init_mg, len, hesh);
	i = 0;
	while (i < hesh->ini.bias)
	{
		ft_arshed(i, hesh);
		j = -1;
		while (++j < MIN_BIT)
			ft_calc_sha256(j, hesh);
		ft_compreh(hesh);
		free(hesh->dls.torl);
		i++;
	}
	free(hesh->dls.sys32);
	return (0);
}
