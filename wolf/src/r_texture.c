/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:25:34 by rhusak            #+#    #+#             */
/*   Updated: 2018/10/01 15:43:32 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_r_texture1(char **texture, t_mlx *mlx)
{
	int			i;
	char		*type_tex;

	i = 0;
	while (i < 20 && texture[i])
	{
		type_tex = ft_strjoin("texture/", texture[i]);
		ft_convert(mlx, type_tex, i);
		ft_strdel(&type_tex);
		i++;
	}
}

void		ft_r_texture2(char **texture, t_mlx *mlx)
{
	int			i;
	char		*type_tex;

	i = 0;
	while (i < 20 && texture[i])
	{
		type_tex = ft_strjoin("texture/NAZI/", texture[i]);
		ft_convert(mlx, type_tex, i);
		ft_strdel(&type_tex);
		i++;
	}
}

void		ft_menu(t_mlx *mlx, int a, int b)
{
	if ((mlx->menu1 = mlx_xpm_file_to_image(mlx->mlx,
		"start/menu1.xpm", &a, &b)) == NULL)
	{
		if (ft_del_picture(mlx, mlx->menu1) == NULL)
		{
			ft_strcol("Start screen error\n", GREY);
			exit(EXIT_SUCCESS);
		}
	}
	if ((mlx->menu2 = mlx_xpm_file_to_image(mlx->mlx,
		"start/menu2.xpm", &a, &b)) == NULL)
	{
		if (ft_del_picture(mlx, mlx->menu2) == NULL)
		{
			ft_strcol("Start screen error\n", GREY);
			exit(EXIT_SUCCESS);
		}
	}
}
