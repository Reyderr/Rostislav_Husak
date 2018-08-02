/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:03:39 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/02 12:28:06 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_clear_picture(t_picture *picture)
{
	ft_bzero(picture->addr, WIN_WD * WIN_HG * picture->bits_per_pixel);
}

t_picture	*ft_del_picture(t_mlx *mlx, t_picture *pic)
{
	if (pic != NULL)
	{
		if (pic->picture != NULL)
			mlx_destroy_image(mlx->mlx, pic->picture);
		ft_memdel((void **)&pic);
	}
	return (NULL);
}

t_picture	*ft_new_picture(t_mlx *mlx)
{
	t_picture		*pic;

	if ((pic = ft_memalloc(sizeof(t_picture))) == NULL)
		return (NULL);
	if ((pic->picture = mlx_new_image(mlx->mlx, WIN_WD, WIN_HG)) == NULL)
		return (ft_del_picture(mlx, pic));
	pic->addr = mlx_get_data_addr(pic->picture, &pic->bits_per_pixel,
	&pic->sz_line, &pic->endian);
	pic->bits_per_pixel /= 8;
	return (pic);
}
