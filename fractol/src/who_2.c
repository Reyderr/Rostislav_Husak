/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:05:55 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/15 14:05:56 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void	ft_b_spider(t_mlx *mlx)
{
	mlx->maxiter = 50;
	ft_var(mlx);
}

void	ft_b_bship(t_mlx *mlx)
{
	mlx->maxiter = 50;
	ft_var(mlx);
}
