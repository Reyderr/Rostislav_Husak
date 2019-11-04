/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sha512.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:53:30 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/31 10:53:32 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	big_64_endian(uint64_t val)
{
	return (((val >> 56) & 0xff) |
			((val >> 40) & 0xff00) |
			((val >> 24) & 0xff0000) |
			((val >> 8) & 0xff000000) |
			((val << 8) & 0xff00000000) |
			((val << 24) & 0xff0000000000) |
			((val << 40) & 0xff000000000000) |
			((val << 56) & 0xff00000000000000));
}

uint64_t	ft_ris(uint64_t val, uint64_t shift1,
			uint64_t shift2, uint64_t shift3)
{
	uint64_t	vec1;
	uint64_t	vec2;
	uint64_t	vec3;

	vec1 = (RIGHT_64_ROTATE(val, shift1));
	vec2 = (RIGHT_64_ROTATE(val, shift2));
	vec3 = val >> shift3;
	return (vec1 ^ vec2 ^ vec3);
}

void		ft_hs(t_hs512 *hesh, uint64_t *message)
{
	int i;

	i = 16;
	while (i < 80)
	{
		hesh->s0 = ft_ris(message[i - 15], 1, 8, 7);
		hesh->s1 = ft_ris(message[i - 2], 19, 61, 6);
		message[i] = message[i - 16] + hesh->s0 + message[i - 7] + hesh->s1;
		i++;
	}
}

uint64_t	ft_zsg(uint64_t val, uint64_t rot1, uint64_t rot2, uint64_t rot3)
{
	uint64_t	vec1;
	uint64_t	vec2;
	uint64_t	vec3;

	vec1 = (RIGHT_64_ROTATE(val, rot1));
	vec2 = (RIGHT_64_ROTATE(val, rot2));
	vec3 = (RIGHT_64_ROTATE(val, rot3));
	return (vec1 ^ vec2 ^ vec3);
}

char		*ft_red_itoa64(uint64_t ts)
{
	char	*line;
	char	*dec;
	int		l;
	int		tt;

	dec = "0123456789abcdef";
	l = ft_delimer(4, ts);
	if (ts == 0)
		return (ft_strdup("0"));
	tt = l + 1;
	if (!(line = (char *)malloc(sizeof(char) * (tt))))
		return (NULL);
	line[tt] = 0;
	while (l + 1)
	{
		line[l] = dec[ts % 16];
		ts = ts / 16;
		l--;
	}
	if (line[0] == '0')
		line = ft_freeing(line);
	return (line);
}
