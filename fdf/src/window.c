/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:56:03 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/02 12:55:01 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_move_w(int key, t_mlx *mlx)
{
	if (key == 126)
		mlx->cam->offsety -= 10;
	if (key == 125)
		mlx->cam->offsety += 10;
	if (key == 123)
		mlx->cam->offsetx -= 10;
	if (key == 124)
		mlx->cam->offsetx += 10;
}

t_mlx		*ft_mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->picture != NULL)
		ft_del_picture(mlx, mlx->picture);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*ft_create(char *text)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WD,
			WIN_HG, text)) == NULL ||
		(mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL ||
		(mlx->picture = ft_new_picture(mlx)) == NULL)
		return (ft_mlxdel(mlx));
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->scale = 40;
	mlx->cam->offsetx = WIN_WD / 2;
	mlx->cam->offsety = WIN_HG / 2;
	return (mlx);
}
