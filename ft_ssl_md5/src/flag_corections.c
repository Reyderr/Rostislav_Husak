/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manang.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:28:27 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:28:31 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			ft_f_dism(char **argv, t_hesh *hesh)
{
	int num;

	num = hesh->rost;
	if ((hesh->fd = open(argv[num], O_RDWR)) < 0)
	{
		if (hesh->type_hesh == 2)
			ft_putstr("ft_ssl: sha256: ");
		else if (hesh->type_hesh == 3)
			ft_putstr("ft_ssl: sha512: ");
		else if (hesh->type_hesh == 4)
			ft_putstr("ft_ssl: sha384: ");
		else
			ft_putstr("ft_ssl: md5: ");
		ft_putstr(argv[num]);
		ft_putstr(": No such file or directory\n");
		hesh->rost++;
		return (-1);
	}
	return (0);
}

void		ft_put_path(char *s)
{
	ft_putstr(" \"");
	ft_putstr(s);
	ft_putendl("\"");
}

void		ft_is_r_on(char **argv, t_hesh *hesh)
{
	int path;

	path = hesh->rost;
	if (hesh->type_hesh == 2)
		ft_start_sha256(argv[path], hesh);
	else if (hesh->type_hesh == 3)
		ft_start_sha512(argv[path]);
	else if (hesh->type_hesh == 4)
		ft_start_sha384(argv[path]);
	else
		ft_start_md5(argv[path], hesh);
	if (!hesh->flags.q_flag)
		ft_put_path(argv[path]);
	else
		ft_putstr("\n");
	path = 0;
}

void		ft_sc_def_rot(char **argv, t_hesh *hesh)
{
	int path;

	if (!hesh->flags.q_flag)
		ft_putdown(argv, hesh);
	path = hesh->rost;
	if (hesh->type_hesh == 2)
		ft_start_sha256(argv[path], hesh);
	else if (hesh->type_hesh == 3)
		ft_start_sha512(argv[path]);
	else if (hesh->type_hesh == 4)
		ft_start_sha384(argv[path]);
	else
		ft_start_md5(argv[path], hesh);
	ft_putchar('\n');
}

int			ft_s_flag(char **argv, t_hesh *hesh, int argc)
{
	if (!ft_no_s_gflag(hesh, argv, argc))
		return (-1);
	else
		hesh->rost++;
	return (0);
}
