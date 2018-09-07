/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:30:19 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/07 12:09:29 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_str(t_mlx *mlx)
{
	char	*str;
	char	*iter;

	iter = ft_itoa(mlx->maxiter);
	str = ft_strjoin("iterations : ", iter);
	mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, str);
	ft_strdel(&str);
	ft_strdel(&iter);

}

void	ft_helper()
{
	ft_putendl("Please choose fractal:\n1)Mandelbrot\n2)Julia\n3)Liambda\n");

}
