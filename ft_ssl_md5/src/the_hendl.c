/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_hendl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:44:03 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/30 07:44:05 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_dsl(t_hesh *hesh, char **a, int ax)
{
	hesh->rost++;
	if (hesh->rost < ax)
	{
		if (hesh->flags.r_flag)
			ft_is_r_on(a, hesh);
		else
			ft_sc_def_rot(a, hesh);
	}
}

int			ft_no_s_gflag(t_hesh *hesh, char **argv, int argc)
{
	if (ft_strcmp("-p", argv[hesh->rost]) == 0)
		hesh->flags.p_flag = 1;
	else if (ft_strcmp("-r", argv[hesh->rost]) == 0)
		hesh->flags.r_flag = 1;
	else if (ft_strcmp("-q", argv[hesh->rost]) == 0)
		hesh->flags.q_flag = 1;
	else if (ft_strcmp("-s", argv[hesh->rost]) == 0)
		ft_dsl(hesh, argv, argc);
	else
		return (0);
	return (1);
}

void		ft_start(int argc, t_hesh *hesh, char **argv)
{
	int tp;

	ft_init(hesh);
	while (hesh->ini.argc < argc)
	{
		if (!ft_no_s_flag(hesh, argv))
			break ;
	}
	tp = hesh->ini.argc - argc;
	hesh->ini_f = tp;
}

void		ft_putdown(char **argv, t_hesh *hesh)
{
	if (hesh->type_hesh == 2)
		ft_putstr("SHA256 (\"");
	else
		ft_putstr("MD5 (\"");
	ft_putstr(argv[hesh->rost]);
	ft_putstr("\") = ");
}

void		ft_de_ini(t_hesh *hesh)
{
	hesh->block.a = hesh->head.heshes0;
	hesh->block.b = hesh->head.heshes1;
	hesh->block.c = hesh->head.heshes2;
	hesh->block.d = hesh->head.heshes3;
	hesh->block.e = hesh->sha_h.hesh0;
	hesh->block.f = hesh->sha_h.hesh1;
	hesh->block.g = hesh->sha_h.hesh2;
	hesh->block.h = hesh->sha_h.hesh3;
}
