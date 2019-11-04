/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sha384.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:40:59 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/31 10:41:00 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t		ft_pop(uint64_t val, uint64_t shift1, uint64_t shift2,
				uint64_t shift3)
{
	uint64_t	v1;
	uint64_t	v2;
	uint64_t	v3;

	v1 = (RIGHT_64_ROTATE(val, shift1));
	v2 = (RIGHT_64_ROTATE(val, shift2));
	v3 = val >> shift3;
	return (v1 ^ v2 ^ v3);
}

uint64_t		ft_pip(uint64_t val,
				uint64_t rot1, uint64_t rot2, uint64_t rot3)
{
	uint64_t	v1;
	uint64_t	v2;
	uint64_t	v3;

	v1 = (RIGHT_64_ROTATE(val, rot1));
	v2 = (RIGHT_64_ROTATE(val, rot2));
	v3 = (RIGHT_64_ROTATE(val, rot3));
	return (v1 ^ v2 ^ v3);
}

void			ft_ds(t_hs384 *hesh, uint64_t *message)
{
	int			i;

	i = 16;
	while (i < 80)
	{
		hesh->s0 = ft_pop(message[i - 15], 1, 8, 7);
		hesh->s1 = ft_pop(message[i - 2], 19, 61, 6);
		message[i] = message[i - 16] + hesh->s0 + message[i - 7] + hesh->s1;
		i++;
	}
}

char			*ft_red_itoa38(uint64_t ts)
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
