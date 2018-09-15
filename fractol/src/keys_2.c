/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:46:08 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/15 13:46:09 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_epileptic(t_mlx *mlx)
{
	mlx->rd = rand() % 255 + 1;
	mlx->gr = rand() % 255 + 1;
	mlx->bl = rand() % 255 + 1;
}

void	ft_rand_col(int key, t_mlx *mlx)
{
	if (key == 81)
		mlx->rd = rand() % 255 + 1;
	if (key == 75)
		mlx->gr = rand() % 255 + 1;
	if (key == 67)
		mlx->bl = rand() % 255 + 1;
}

void	ft_iterations(int key, t_mlx *mlx)
{
	if (key == 69)
		mlx->maxiter++;
	if (key == 78)
		mlx->maxiter--;
	ft_var(mlx);
}

void	ft_choise(int key, t_mlx *mlx)
{
	if (key == 83)
		mlx->fract = 1;
	if (key == 84)
		mlx->fract = 2;
	if (key == 85)
		mlx->fract = 3;
	if (key == 86)
		mlx->fract = 4;
	if (key == 87)
		mlx->fract = 5;
	ft_begin(mlx);
}

void	ft_lock(t_mlx *mlx)
{
	if (mlx->lock == 0)
		mlx->lock = 1;
	else
		mlx->lock = 0;
	ft_var(mlx);
}
