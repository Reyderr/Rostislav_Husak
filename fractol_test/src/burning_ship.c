/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:49:17 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/08 15:26:12 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_bship_doub(float *real, float *imagine, float dx, float dy)
{
	float sq_real;
    float sq_imagine;
    float doub;

    sq_real = *real * *real;
    sq_imagine = *imagine * *imagine;
    doub = 2.0 * *real * *imagine;
    *real = fabs(sq_real - sq_imagine + dx);
    *imagine = fabs(doub + dy);
}

void	ft_bship_c(t_mlx *mlx)
{
	float	real;
	float	imagine;
	double	dx;
	double	dy;
	int		n;

	dx = mlx->re_min + mlx->wd * (mlx->re_max - mlx->re_min) / (WIN_WD - 1);	
  	dy = mlx->im_min + mlx->hg * (mlx->im_max - mlx->im_min) / (WIN_HG - 1);
	real = 0;
    imagine = 0;
    n = 0;
    while (n < mlx->maxiter) 
    {
    	ft_bship_doub(&real, &imagine, dx, dy);
    	if (real * real + imagine * imagine > 4) 
          	break; 
        n++;
   	}
    if (n < mlx->maxiter)
		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
   	else
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
}

void	*ft_bship(void *multi)
{
	double	tmp;
	t_mlx 	*mlx;

	mlx = (t_mlx *)multi;
	mlx->wd = 0;
	tmp = mlx->wd;
	while (mlx->hg < mlx->hgg)
	{
		mlx->wd = tmp;
		while(mlx->wd < WIN_WD)
		{
			ft_bship_c(mlx);
			mlx->wd++;
		}
		mlx->hg++;
	}
	return(multi);
}

void	ft_multi_bship(t_mlx *mlx)
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
		pthread_create(&ptr[i - 1], NULL, ft_bship, &multi[i - 1]);
	while (i--)
		pthread_join(ptr[i], NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}
