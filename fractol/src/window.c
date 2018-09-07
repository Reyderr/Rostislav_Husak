/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:46:23 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 14:21:05 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_pict	*ft_del_picture(t_mlx *mlx, t_pict *pic)
{
	if (pic != NULL)
	{
		if (pic->picture != NULL)
			mlx_destroy_image(mlx->mlx, pic->picture);
		ft_memdel((void **)&pic);
	}
	return (NULL);
}

t_pict	*ft_new_picture(t_mlx *mlx)
{
	t_pict		*pic;

	if ((pic = ft_memalloc(sizeof(t_pict))) == NULL)
		return (NULL);
	if ((pic->picture = mlx_new_image(mlx->mlx, WIN_WD, WIN_HG)) == NULL)
		return (ft_del_picture(mlx, pic));
	pic->addr = mlx_get_data_addr(pic->picture, &pic->bits_per_pixel,
	&pic->sz_line, &pic->endian);
	pic->bits_per_pixel /= 8;
	return (pic);
}

t_mlx		*ft_mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->picture != NULL)
		ft_del_picture(mlx, mlx->picture);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*ft_start(void)
{
	t_mlx	*mlx;

	if((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return(NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WD,
			WIN_HG, "Fractol")) == NULL ||
		(mlx->picture = ft_new_picture(mlx)) == NULL)
		return (ft_mlxdel(mlx));
	return(mlx);
}