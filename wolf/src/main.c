/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:15 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/24 15:33:51 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int		ft_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void		ft_begin(t_mlx *mlx)
{
	mlx->d_x = -1;
	mlx->d_y = 0;
	mlx->pl_x = 0;
	mlx->pl_y = 0.7;  
} 

void		ft_convert(t_mlx *mlx, char *name, int i)
{
	int 		a;
	int		b;

	a = 64;
	b = 64;
	if ((mlx->texture[i].picture = mlx_xpm_file_to_image(mlx->mlx, name, &a, &b)) == NULL)
		ft_del_picture(mlx, &mlx->texture[i]);
	mlx->texture[i].addr = mlx_get_data_addr(mlx->texture[i].picture, &mlx->texture[i].bits_per_pixel, &mlx->texture[i].sz_line, &mlx->texture[i].endian);
	mlx->texture[i].bits_per_pixel /= 8;
}

int		ft_texture(t_mlx *mlx)
{
	int		i;
	char		*texture[20] = {"r_brick.xpm", "wood.xpm", "eagle.xpm",
		"b_stone.xpm", "c_stone.xpm", "girl.xpm", "portal.xpm",  NULL};
	char		*type_tex;

	i = 0;
	while(i < 20 && texture[i])
	{
		type_tex = ft_strjoin("texture/pics/", texture[i]);
		ft_convert(mlx, type_tex, i);
		ft_strdel(&type_tex);
		i++;
	}
	return (0);
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
	ft_command();
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