/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:55:17 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/30 12:55:18 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static	uint64_t	g_k[80] =
{
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

void			ft_dss(t_hs384 *hesh, uint64_t *message, uint64_t *hash)
{
	int i;

	i = 0;
	while (i < 80)
	{
		hesh->s1 = ft_pip(hash[4], 14, 18, 41);
		hesh->zm = (hash[4] & hash[5]) ^ ((~hash[4]) & hash[6]);
		hesh->tp = hash[7] + hesh->s1 + hesh->zm + g_k[i] + message[i];
		hesh->s0 = ft_pip(hash[0], 28, 34, 39);
		hesh->gs = (hash[0] & hash[1])
		^ (hash[0] & hash[2]) ^ (hash[1] & hash[2]);
		hesh->tps = hesh->s0 + hesh->gs;
		hash[7] = hash[6];
		hash[6] = hash[5];
		hash[5] = hash[4];
		hash[4] = hash[3] + hesh->tp;
		hash[3] = hash[2];
		hash[2] = hash[1];
		hash[1] = hash[0];
		hash[0] = hesh->tp + hesh->tps;
		i++;
	}
}

void			ft_strs_sha384(uint64_t *stack, uint64_t *hh)
{
	t_hs384		hesh;
	uint64_t	hash[8];
	uint64_t	message[80];
	int			i;

	ft_memcpy(hash, hh, 64);
	i = 0;
	while (i < 16)
	{
		message[i] = big_64_endian(stack[i]);
		i++;
	}
	ft_ds(&hesh, message);
	ft_dss(&hesh, message, hash);
	i = 0;
	while (i < 8)
	{
		hh[i] = hh[i] + hash[i];
		i++;
	}
}

void			ft_ini_384(uint64_t *hh)
{
	hh[0] = 0xcbbb9d5dc1059ed8;
	hh[1] = 0x629a292a367cd507;
	hh[2] = 0x9159015a3070dd17;
	hh[3] = 0x152fecd8f70e5939;
	hh[4] = 0x67332667ffc00b31;
	hh[5] = 0x8eb44a8768581511;
	hh[6] = 0xdb0c2e0d64f98fa7;
	hh[7] = 0x47b5481dbefa4fa4;
}

void			ft_calc_384(uint8_t *stack, uint64_t size, uint64_t *hh)
{
	uint64_t	calc;
	size_t		len;
	size_t		i;

	i = 0;
	calc = (128 - ((size + 17) % 128));
	len = size + 17 + calc;
	ft_bzero(stack + size + 1, calc);
	*(uint64_t*)(stack + len - 8) = big_64_endian(size * 8);
	*(uint64_t*)(stack + len - 16) = big_64_endian((size >> 61));
	while (i < len)
	{
		ft_strs_sha384((uint64_t*)(stack + i), hh);
		i += 128;
	}
}

void			ft_st_sha384(char *str)
{
	uint64_t	size;
	uint8_t		*stack;
	uint64_t	hh[8];
	size_t		i;

	ft_ini_384(hh);
	size = ft_strlen(str);
	if (!(stack = malloc(size * 128)))
		ft_error_init();
	ft_memcpy(stack, str, size);
	stack[size] = 0x80;
	ft_calc_384(stack, size, hh);
	i = 0;
	while (i < 6)
	{
		ft_adddls(ft_red_itoa38(hh[i]));
		i++;
	}
	free(stack);
}
