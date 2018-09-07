/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liambda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:12:01 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 14:19:41 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_l_doub(float *real, float *imagine, float dx, float dy)
{
	float sq_real;
    float sq_imagine;
    float doub;

    sq_imagine = *imagine * *imagine;
    sq_real = *imagine - (*real * *real) + sq_imagine;
    doub = *imagine - 2.0 * *real * *imagine;
    *real = dy * sq_real - dx * doub;
    *imagine = dy * doub + dx * sq_real;
}

void	ft_l_c(t_mlx *mlx)
{
	float	real;
	float	imagine;
	float	dx;
	float	dy;
	int		n;

	dy = /*((mlx->hg * 0.1 + 1) - WIN_HG / 2)*/			((mlx->hg - WIN_HG / 2) * 0.1 + 1) / (0.4 * WIN_HG);
	dx = /*1.5 * ((mlx->wd * 0.01) - WIN_WD / 2)*/		1.5 * (mlx->wd - WIN_WD / 2) * 0.01 / (0.4 * WIN_WD) ;
	real = 0.5;
    imagine = 0;
    n = 0;
    while (n < mlx->maxiter) 
    {
    	ft_l_doub(&real, &imagine, dx, dy);
    	if (real * real + imagine * imagine > 4) 
          	break; 
        n++;
   	}
    if (n < mlx->maxiter)
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
   	else
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
}

void	*ft_liambda(void *multi)
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
			ft_l_c(mlx);
			mlx->wd++;
		}
		mlx->hg++;
	}
	return(multi);
}

void	ft_multi_liambda(t_mlx *mlx)
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
		pthread_create(&ptr[i - 1], NULL, ft_liambda, &multi[i - 1]);
	while (i--)
		pthread_join(ptr[i], NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}