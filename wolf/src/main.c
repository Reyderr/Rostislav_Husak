/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:15 by rhusak            #+#    #+#             */
/*   Updated: 2018/10/01 15:43:14 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	ft_begin(t_mlx *mlx)
{
	mlx->d_x = -1;
	mlx->d_y = 0;
	mlx->pl_x = 0;
	mlx->pl_y = 0.7;
	mlx->n_text = 0;
}

void	ft_start_screen(t_mlx *mlx)
{
	int	a;
	int	b;

	a = 1024;
	b = 800;
	mlx->init = 0;
	if ((mlx->background = mlx_xpm_file_to_image(mlx->mlx,
		"start/win1.xpm", &a, &b)) == NULL)
	{
		if (ft_del_picture(mlx, mlx->background) == NULL)
		{
			ft_strcol("Start screen error\n", GREY);
			exit(EXIT_SUCCESS);
		}
	}
	ft_menu(mlx, a, b);
	ft_rend_screen(mlx);
}

int		ft_fps(t_mlx *mlx)
{
	ft_calc(mlx);
	mlx_hook(mlx->window, 6, 1L < 6, ft_maus, mlx);
	return (0);
}

void	ft_wolf(t_mlx *mlx)
{
	ft_begin(mlx);
	ft_command();
	mlx_loop_hook(mlx->mlx, ft_fps, mlx);
}

int		main(int ac, char **av)
{
	t_mlx			*mlx;
	t_map			*map;
	int				fd;

	if (ac != 2)
		return (ft_strcol("Incorrect argument\n", RED));
	fd = open(av[1], O_RDONLY);
	if ((mlx = ft_starting()) == NULL)
		return (ft_strcol("Init error", RED));
	if ((map = ft_read_file(av[1])) == NULL)
		return (ft_strcol("File read error\n", GREEN));
	if (fd < 0)
		return (ft_strcol("File read error\n", BLUE));
	mlx->map = map;
	mlx->lock = 0;
	mlx->i_key = 0;
	ft_chtexture(mlx);
	ft_start_screen(mlx);
	mlx_hook(mlx->window, 2, 3, ft_button_pressig, mlx);
	mlx_key_hook(mlx->window, ft_exit, mlx);
	mlx_hook(mlx->window, 17, 0, ft_exit_x, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
