/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:22:40 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 14:18:59 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_spider_doub(t_mlx *mlx)
{
	mlx->tmp = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i;
	mlx->z_i = 2 * mlx->z_r * mlx->z_i + mlx->dy;
	mlx->z_r = mlx->tmp + mlx->dx;
	mlx->dx = mlx->dx / 2 + mlx->z_r;
	mlx->dy = mlx->dy / 2 + mlx->z_i;
	mlx->iter++;
}

void	ft_sp_c(t_mlx *mlx)
{
	mlx->dx = mlx->re_min + mlx->wd * (mlx->re_max - mlx->re_min)\
	/ (WIN_WD - 1) + mlx->move_x;
	mlx->dy = mlx->im_min + mlx->hg * (mlx->im_max - mlx->im_min)\
	/ (WIN_HG - 1) + mlx->move_y;
	mlx->z_r = mlx->dx;
	mlx->z_i = mlx->dy;
	mlx->iter = 0;
	while (mlx->iter < mlx->maxiter && mlx->z_r * mlx->z_r + mlx->z_i\
		* mlx->z_i < 4)
		ft_spider_doub(mlx);
	if (mlx->iter < mlx->maxiter)
		ft_pixel_color(mlx, mlx->wd, mlx->hg, mlx->iter);
	else
		ft_pixel_color(mlx, mlx->wd, mlx->hg, mlx->iter);
}

void	*ft_spider(void *multi)
{
	double	tmp;
	t_mlx	*mlx;

	mlx = (t_mlx *)multi;
	mlx->wd = 0;
	tmp = mlx->wd;
	while (mlx->hg < mlx->hgg)
	{
		mlx->wd = tmp;
		while (mlx->wd < WIN_WD)
		{
			ft_sp_c(mlx);
			mlx->wd++;
		}
		mlx->hg++;
	}
	return (multi);
}

void	ft_multi_spider(t_mlx *mlx)
{
	t_mlx		multi[8];
	pthread_t	ptr[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&multi[i], (void*)mlx, sizeof(t_mlx));
		multi[i].hg = 100 * i;
		multi[i].hgg = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&ptr[i - 1], NULL, ft_spider, &multi[i - 1]);
	while (i--)
		pthread_join(ptr[i], NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}
