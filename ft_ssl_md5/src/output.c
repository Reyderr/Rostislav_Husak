/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:28:54 by rhusak            #+#    #+#             */
/*   Updated: 2019/10/29 12:28:57 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_adddls(char *c)
{
	ft_zero_inp(c);
	ft_putstr(c);
	free(c);
}

void		ft_start_md5(char *std, t_hesh *hesh)
{
	char	*str;

	if (ft_st_md5((uint8_t *)std, ft_strlen(std), hesh) == -1)
		return ;
	str = ft_red_itoa32(ft_rev(hesh->head.heshes0));
	ft_adddls(str);
	str = ft_red_itoa32(ft_rev(hesh->head.heshes1));
	ft_adddls(str);
	str = ft_red_itoa32(ft_rev(hesh->head.heshes2));
	ft_adddls(str);
	str = ft_red_itoa32(ft_rev(hesh->head.heshes3));
	ft_adddls(str);
}

void		ft_start_sha256(char *std, t_hesh *hesh)
{
	char	*str;

	if (ft_st_sha256(std, ft_strlen(std), hesh) == -1)
		return ;
	str = ft_red_itoa32(hesh->head.heshes0);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->head.heshes1);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->head.heshes2);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->head.heshes3);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->sha_h.hesh0);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->sha_h.hesh1);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->sha_h.hesh2);
	ft_adddls(str);
	str = ft_red_itoa32(hesh->sha_h.hesh3);
	ft_adddls(str);
}

void		ft_start_sha512(char *std)
{
	ft_st_sha512(std);
}

void		ft_start_sha384(char *std)
{
	ft_st_sha384(std);
}
