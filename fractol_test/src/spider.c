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

// void	ft_spider_doub(float *real, float *imagine, float dx, float dy)
// {
// 	float tmp_r;
//     float tmp_i;
//     float doub;

//     tmp_r = dx;
//     tmp_i = dy;
//     dx = ()
// }

void	ft_sp_c(t_mlx *mlx)
{
	float	real;
	float	imagine;
	float	dx;
	float	dy;
	int		n;

	dy = (mlx->hg - WIN_HG / 2) / (0.4 * WIN_HG);
	dx = 1.5 * (mlx->wd - WIN_WD / 2) / (0.4 * WIN_WD) - 0.5;
	real = dx;																				// real == c1.x   z1.x == dx
    imagine = dy;																			// imagine == c1.y 	z1.y == dy
    n = 0;
    while (n < mlx->maxiter) 
    {
    	//ft_spider_doub(&real, &imagine, dx, dy);
    	if (real * real + imagine * imagine > 4) 
          	break; 
        n++;
   	}
    if (n < mlx->maxiter)
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
   	else
   		ft_pixel_color(mlx, mlx->wd, mlx->hg, n);
}

void	*ft_spider(void *multi)
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
			ft_sp_c(mlx);
			mlx->wd++;
		}
		mlx->hg++;
	}
	return(multi);
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




