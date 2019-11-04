/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_norme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:27:48 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:27:51 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_type_n(char **argv, t_hesh *hesh)
{
	int te;

	te = hesh->rost;
	if (hesh->type_hesh == 2)
		ft_start_sha256(hesh->input_l, hesh);
	else if (hesh->type_hesh == 3)
		ft_st_sha512(hesh->input_l);
	else if (hesh->type_hesh == 4)
		ft_st_sha384(hesh->input_l);
	else
		ft_start_md5(hesh->input_l, hesh);
	if (!hesh->flags.q_flag)
		ft_wrong(argv[te]);
	else
		ft_putstr("\n");
}

int			ft_delimer(int done, int num)
{
	int count;
	int tmp;

	tmp = num;
	count = 0;
	while (tmp != 0)
	{
		tmp = tmp / done;
		count++;
	}
	return (count);
}

char		*ft_freeing(char *line)
{
	char *qw;

	qw = line;
	line = ft_strsub(line, 1, ft_strlen(line) - 1);
	free(qw);
	return (line);
}

char		*ft_red_itoa32(uint32_t ts)
{
	char	*line;
	char	*dec;
	int		l;
	int		tt;

	dec = "0123456789abcdef";
	l = ft_delimer(16, ts);
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
