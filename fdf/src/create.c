/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:56:03 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 15:46:35 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_move_w(int key, t_mlx *mlx)
{
	if (key == 126)
		mlx->eyes->o_y -= 10;
	if (key == 125)
		mlx->eyes->o_y += 10;
	if (key == 123)
		mlx->eyes->o_x -= 10;
	if (key == 124)
		mlx->eyes->o_x += 10;
}

t_mlx		*ft_mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->eyes != NULL)
		ft_memdel((void **)&mlx->eyes);
	if (mlx->picture != NULL)
		ft_del_picture(mlx, mlx->picture);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*ft_create(void)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL)
		return (ft_mlxdel(mlx));
	if ((mlx->window = mlx_new_window(mlx->mlx, WIN_WD,
			WIN_HG, "FDF")) == NULL ||
		(mlx->eyes = ft_memalloc(sizeof(t_eyes))) == NULL ||
		(mlx->picture = ft_new_picture(mlx)) == NULL)
		return (ft_mlxdel(mlx));
	mlx->eyes->incr = 40;
	mlx->eyes->o_x = WIN_WD / 2;
	mlx->eyes->o_y = WIN_HG / 2;
	mlx->eyes->x = 0.06;
	mlx->eyes->y = 0.1;
	return (mlx);
}
