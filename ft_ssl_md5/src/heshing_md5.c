/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:28:40 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:28:44 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

const uint32_t g_r[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
	23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21
};

const uint32_t g_k[] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void		ft_hrs(t_hesh *hesh, int n)
{
	hesh->bl.a1 = hesh->block.d;
	hesh->block.d = hesh->block.c;
	hesh->block.c = hesh->block.b;
	hesh->block.b = hesh->block.b + LEFTROTATE((hesh->block.a
		+ hesh->block.f + g_k[n] + hesh->dls.torl[hesh->block.g]), g_r[n]);
	hesh->block.a = hesh->bl.a1;
}

void		ft_processing(t_hesh *hesh, int num)
{
	if (num < 16)
	{
		hesh->block.f = (hesh->block.b & hesh->block.c)
		| ((~hesh->block.b) & hesh->block.d);
		hesh->block.g = num;
	}
	else if (num < 32)
	{
		hesh->block.f = (hesh->block.d & hesh->block.b)
		| ((~hesh->block.d) & hesh->block.c);
		hesh->block.g = (5 * num + 1) % 16;
	}
	else if (num < 48)
	{
		hesh->block.f = hesh->block.b ^ hesh->block.c ^ hesh->block.d;
		hesh->block.g = (3 * num + 5) % 16;
	}
	else
	{
		hesh->block.f = hesh->block.c ^ (hesh->block.b | (~hesh->block.d));
		hesh->block.g = (7 * num) % 16;
	}
	ft_hrs(hesh, num);
}

void		ft_yop1(t_hesh *hesh)
{
	hesh->head.heshes0 += hesh->block.a;
	hesh->head.heshes1 += hesh->block.b;
	hesh->head.heshes2 += hesh->block.c;
	hesh->head.heshes3 += hesh->block.d;
	hesh->ini.bias += MIN_BIT;
}

int			ft_oss(unsigned char *init_mg, size_t len, t_hesh *hesh)
{
	int z;

	ft_initialaze(hesh);
	hesh->ini.next_l = len + 1;
	while (hesh->ini.next_l % (BITOVOCH / 8) != 448 / 8)
		hesh->ini.next_l++;
	if (!(hesh->input_line = malloc(hesh->ini.next_l + MIN_BIT)))
		return (-1);
	z = hesh->ini.next_l + MIN_BIT;
	hesh->input_line = ft_bzero(hesh->input_line, z);
	ft_strcpy((char*)hesh->input_line, (const char *)init_mg);
	ft_spo(hesh, len);
	return (0);
}

int			ft_st_md5(unsigned char *init_mg, size_t len, t_hesh *hesh)
{
	int q;
	int tp;
	int z;

	z = ft_oss(init_mg, len, hesh);
	tp = ft_oss(init_mg, len, hesh);
	if (tp == -1)
		return (-1);
	while (hesh->ini.bias < hesh->ini.next_l)
	{
		ft_yop(hesh);
		q = -1;
		while (++q < MIN_BIT)
			ft_processing(hesh, q);
		ft_yop1(hesh);
	}
	free(hesh->input_line);
	return (0);
}
