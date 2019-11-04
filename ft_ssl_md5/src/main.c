/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:28:15 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:28:18 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_rofl(t_hesh *hesh)
{
	ft_js_qs(0, hesh);
	if (hesh->flags.p_flag)
		ft_putstr(hesh->input_l);
	if (hesh->type_hesh == 2)
		ft_start_sha256(hesh->input_l, hesh);
	else if (hesh->type_hesh == 3)
		ft_start_sha512(hesh->input_l);
	else if (hesh->type_hesh == 4)
		ft_start_sha384(hesh->input_l);
	else
		ft_start_md5(hesh->input_l, hesh);
	ft_putstr("\n");
	free(hesh->input_l);
}

void		ft_checking(t_hesh *hesh, int cout, char **str)
{
	while (hesh->rost < cout)
		if (ft_s_flag(str, hesh, cout) == -1)
			break ;
	while (hesh->rost < cout)
		ft_is_r_flag(hesh, str);
}

void		ft_choise(char **av, int ac, t_hesh *hesh)
{
	int acer;

	acer = ac;
	ft_start(acer, hesh, av);
	if (hesh->flags.p_flag || (!hesh->ini_f && !hesh->flags.s_flag))
		ft_rofl(hesh);
	hesh->rost = 2;
	ft_checking(hesh, acer, av);
}

void		ft_choose_heshing(char *str, t_hesh *hesh)
{
	if (ft_strcmp(str, "md5") == 0)
		hesh->type_hesh = 1;
	else if (ft_strcmp(str, "sha256") == 0)
		hesh->type_hesh = 2;
	else if (ft_strcmp(str, "sha512") == 0)
		hesh->type_hesh = 3;
	else if (ft_strcmp(str, "sha384") == 0)
		hesh->type_hesh = 4;
	else
		hesh->type_hesh = -1;
}

int			main(int ac, char **av)
{
	t_hesh	hesh;

	if (ac == 1)
		ft_erro(1);
	ft_choose_heshing(av[1], &hesh);
	if (!(hesh.type_hesh == 1) && !(hesh.type_hesh == 2) &&
			!(hesh.type_hesh == 3) && !(hesh.type_hesh == 4))
		ft_erro_comand(av[1]);
	else
		ft_choise(av, ac, &hesh);
	return (0);
}
