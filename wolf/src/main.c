/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:15 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/21 11:34:28 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

int		ft_strcol(char *str, char *color)
{
	if (color)
	{
		write(1, color, ft_strlen(color));
		write(1, str, ft_strlen(str));
		write(1, END, ft_strlen(END));
	}
	return(1);
}

void		ft_begin(t_mlx *mlx)
{
	mlx->d_x = -1;
	mlx->d_y = 0;
	mlx->pl_x = 0;
	mlx->pl_y = 0.66;  
} 


ft_texture(t_mlx *mlx)
{
	int	y;
	int	x;
	int	gradi;

	x = 0;
	while(x < 64)
	{
		y = 0;
		while(y < 64)
		{
			gradi = (x * 256 / 64) * (y * 256 / 64);
			mlx->texture[64 * y + x] =  gradi + 256 * gradi + 65536 * gradi;
			y++;
		}
		x++;
	}



}

int		main(int ac, char **av)
{
	t_mlx		*mlx;
	t_map		*map;
	int		fd;
	
	if (ac != 2)
		return(ft_strcol("Incorrect argument\n", RED));
	fd = open(av[1], O_RDONLY);
	if ((mlx = ft_starting()) == NULL)
		return(ft_strcol("Init error", RED));
	if((map = ft_read_file(av[1])) == NULL)
		return(ft_strcol("File read error\n",  GREEN));
	if (fd < 0 )
		return (ft_strcol("File read error\n",  BLUE));
	mlx->map = map;
	mlx->lock = 0;
	ft_texture(mlx);
	ft_begin(mlx);
	ft_calc(mlx);
	mlx_hook(mlx->window, 2, 3, ft_button_pressig, mlx);
	mlx_key_hook(mlx->window, ft_exit, mlx);
	mlx_hook(mlx->window, 17, 0, ft_exit_x, mlx);
	mlx_hook(mlx->window, 6, 1L < 6, ft_maus, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}