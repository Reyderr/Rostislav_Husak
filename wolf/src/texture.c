/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:28:29 by rhusak            #+#    #+#             */
/*   Updated: 2018/10/01 14:46:57 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_convert(t_mlx *mlx, char *name, int i)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	if ((mlx->texture[i].picture = mlx_xpm_file_to_image(mlx->mlx,
		name, &a, &b)) == NULL)
	{
		if (ft_del_picture(mlx, &mlx->texture[i]) == NULL)
		{
			ft_strcol("Texture error\n", AQUAMARINE);
			exit(EXIT_SUCCESS);
		}
	}
	mlx->texture[i].addr = mlx_get_data_addr(mlx->texture[i].picture,
		&mlx->texture[i].bits_per_pixel,
		&mlx->texture[i].sz_line, &mlx->texture[i].endian);
	mlx->texture[i].bits_per_pixel /= 8;
}

int			ft_texture(t_mlx *mlx)
{
	char		*texture[20];

	texture[0] = "r_brick.xpm";
	texture[1] = "wood.xpm";
	texture[2] = "stone.xpm";
	texture[3] = "b_stone.xpm";
	texture[4] = "metal.xpm";
	texture[5] = "c_stone.xpm";
	texture[6] = "portal.xpm";
	texture[7] = "portal_2.xpm";
	texture[8] = "mossy.xpm";
	texture[9] = "brick.xpm";
	texture[10] = "grass.xpm";
	texture[11] = "p_stone.xpm";
	texture[12] = "eagle.xpm";
	texture[13] = NULL;
	ft_r_texture1(texture, mlx);
	return (0);
}

int			ft_texture_1(t_mlx *mlx)
{
	char		*texture[20];

	texture[0] = "b_1.xpm";
	texture[1] = "b_2.xpm";
	texture[2] = "g_1.xpm";
	texture[3] = "r_1.xpm";
	texture[4] = "s_3.xpm";
	texture[5] = "r_2.xpm";
	texture[6] = "s_1.xpm";
	texture[7] = "s_2.xpm";
	texture[8] = "w_1.xpm";
	texture[9] = "b_3.xpm";
	texture[10] = "girl.xpm";
	texture[11] = "s_4.xpm";
	texture[12] = "w_2.xpm";
	texture[13] = NULL;
	ft_r_texture2(texture, mlx);
	return (0);
}

void		ft_chtexture(t_mlx *mlx)
{
	if (mlx->n_text == 1)
		ft_texture_1(mlx);
	else
		ft_texture(mlx);
}

void		ft_rend_screen(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->background, 0, 0);
	if (mlx->i_key == 1)
	{
		mlx->exit = 1;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->menu2, 420, 600);
	}
	else
	{
		mlx->exit = 0;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->menu1, 420, 600);
	}
}
