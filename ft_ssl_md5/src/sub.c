/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:38:59 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/30 07:39:01 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_tes(int i, char *s)
{
	if (i == 2)
		ft_putstr("SHA256 (");
	else
		ft_putstr("MD5 (");
	ft_putstr(s);
	ft_putstr(") = ");
}

void		ft_no_r_flag(char **argv, t_hesh *hesh)
{
	int path;

	path = hesh->rost;
	if (!hesh->flags.q_flag)
		ft_tes(hesh->type_hesh, argv[hesh->rost]);
	if (hesh->type_hesh == 2)
		ft_start_sha256(hesh->input_l, hesh);
	else
		ft_start_md5(hesh->input_l, hesh);
	ft_putchar('\n');
}

void		ft_is_r_flag(t_hesh *hesh, char **argv)
{
	if (ft_f_dism(argv, hesh) == -1)
		return ;
	ft_js_qs(hesh->fd, hesh);
	if (!hesh->flags.r_flag)
		ft_no_r_flag(argv, hesh);
	else
		ft_type_n(argv, hesh);
	free(hesh->input_l);
	close(hesh->fd);
	hesh->rost++;
}

void		ft_init(t_hesh *hesh)
{
	hesh->flags.p_flag = 0;
	hesh->flags.q_flag = 0;
	hesh->flags.r_flag = 0;
	hesh->flags.s_flag = 0;
	hesh->ini.argc = 2;
}

int			ft_no_s_flag(t_hesh *hesh, char **argv)
{
	if (ft_strcmp("-p", argv[hesh->ini.argc]) == 0)
		hesh->flags.p_flag = 1;
	else if (ft_strcmp("-q", argv[hesh->ini.argc]) == 0)
		hesh->flags.q_flag = 1;
	else if (ft_strcmp("-r", argv[hesh->ini.argc]) == 0)
		hesh->flags.r_flag = 1;
	else if (ft_strcmp("-s", argv[hesh->ini.argc]) == 0)
	{
		hesh->ini.argc++;
		hesh->flags.s_flag++;
	}
	else
		return (0);
	hesh->ini.argc++;
	return (1);
}
