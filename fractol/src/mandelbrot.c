/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:50:39 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 14:20:40 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_doub(float *real, float *imagine, float dx, float dy)
{
	float sq_real;
    float sq_imagine;
    float doub;

    sq_real = *real * *real;
    sq_imagine = *imagine * *imagine;
    doub = 2.0 * *real * *imagine;
    *real = sq_real - sq_imagine + dx;
    *imagine = doub + dy;
}

void	ft_m_c(t_mlx *mlx)
{
	float	real;
	float	imagine;
	float	dx;
	float	dy;
	int		n;

	dy = (mlx->hg - WIN_HG / 2) / (0.4 * WIN_HG) + mlx->scale;
	dx = 1.5 * (mlx->wd - WIN_WD / 2) / (0.4 * WIN_WD) - 0.5 + mlx->scale;
	real = dx;
    imagine = dy;
    n = 0;
    while (n < mlx->maxiter) 
    {
    	ft_doub(&real, &imagine, dx, dy);
    	if (real * real + imagine * imagine > 4) 
          	break; 
        n++;
   	}
    if (n < mlx->maxiter)
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
   	else
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
}

void	*ft_mandelbrot(void *multi)
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
			ft_m_c(mlx);
			mlx->wd++;
		}
		mlx->hg++;
	}
	return(multi);
}

void	ft_multi_mandelbrot(t_mlx *mlx)
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
		pthread_create(&ptr[i - 1], NULL, ft_mandelbrot, &multi[i - 1]);
	while (i--)
		pthread_join(ptr[i], NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->picture->picture, 0, 0);
}
