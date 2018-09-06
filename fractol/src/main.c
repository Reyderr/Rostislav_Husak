/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:06:58 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/05 11:56:25 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_choose(char **av, t_mlx *mlx)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		mlx->fract = 1;
	else if (ft_strcmp(av[1], "Julia") == 0)
		mlx->fract = 2;
	else
	{
		ft_helper();
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if((mlx = ft_start()) == NULL)
		return(ft_error("ERROR : mlx create error"));
	if (ac != 2)
	{
		ft_helper();
		return(0);
	}
	if(ft_choose(av, mlx) == 0)
		return(0);
	ft_begin(mlx);
	mlx_hook(mlx->window, 6, 1L < 6, m_juli, mlx);
	mlx_hook(mlx->window, 2, 3, ft_press_button, mlx);
	mlx_key_hook(mlx->window, ft_exit, mlx);
	mlx_hook(mlx->window, 17, 0, ft_exit_x, mlx);
	mlx_mouse_hook(mlx->window, ft_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}