/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:41:23 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/18 16:00:35 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void	ft_helper(void *mlx, void *window)
{
	mlx_string_put(mlx, window, 10, 10, 0x00dd00, "Press command on numpad:");
	mlx_string_put(mlx, window, 10, 25, 0x00dd00, "turn left      '4'");
	mlx_string_put(mlx, window, 10, 40, 0x00dd00, "turn right     '6'");
	mlx_string_put(mlx, window, 10, 55, 0x00dd00, "turn top       '8'");
	mlx_string_put(mlx, window, 10, 70, 0x00dd00, "turn bottom    '2'");
	mlx_string_put(mlx, window, 10, 85, 0x00dd00, "back to start  '5'");
	mlx_string_put(mlx, window, 10, 100, 0x00dd00, "zoom out       '-'");
	mlx_string_put(mlx, window, 10, 115, 0x00dd00, "zoom in        '+'");
	mlx_string_put(mlx, window, 10, 130, 0x00dd00, "change color   '/'");
	mlx_string_put(mlx, window, 10, 145, 0x00dd00, "epileptic      '='");
	mlx_string_put(mlx, window, 300, 10, 0x00dd00, "Press arrow to move image");
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_map	*map;
	int		fd;
	t_color	color;

	if (ac < 2)
		return (ft_error("ERROR : Arguments < 2"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_read_file(fd, &map))
		return (ft_error("ERROR : File error"));
	if ((mlx = ft_create()) == NULL)
		return (ft_error("ERROR : mlx create error"));
	mlx->map = map;
	ft_epileptic(&color);
	mlx->color = color;
	ft_render(mlx);
	mlx_hook(mlx->window, 2, 3, ft_press_button, mlx);
	mlx_key_hook(mlx->window, ft_exit, mlx);
	mlx_hook(mlx->window, 17, 0, ft_exit_x, mlx);
	ft_helper(mlx->mlx, mlx->window);
	mlx_loop(mlx->mlx);
	return (0);
}
