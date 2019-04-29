/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:52:29 by rhusak            #+#    #+#             */
/*   Updated: 2018/08/24 15:46:12 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WD	1024
# define WIN_HG	768
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"	
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

typedef	struct			s_eyes
{
	double		o_x;
	double		o_y;
	double		x;
	double		y;
	double		incr;
	double		**matrix;
}						t_eyes;

typedef	struct			s_point
{
	double		x;
	double		y;
	double		z;
}						t_point;

typedef	struct			s_map
{
	int			wd;
	int			hg;
	int			d_max;
	int			d_min;
	t_point		**point;
}						t_map;

typedef	struct			s_picture
{
	void		*picture;
	char		*addr;
	int			bits_per_pixel;
	int			sz_line;
	int			endian;
}						t_picture;

typedef	struct			s_color
{
	int			r;
	int			g;
	int			b;
}						t_color;

typedef	struct			s_mlx
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_picture	*picture;
	t_eyes		*eyes;
	t_color		color;
	double		buffer;
}						t_mlx;

typedef	struct			s_beam
{
	t_point		start;
	int			dx;
	int			f_bias;
	int			s_bias;
	int			dy;
	int			check_x;
	int			check_y;
	t_point		stop;
}						t_beam;

int						ft_exit_x(void *par);
t_mlx					*ft_mlxdel(t_mlx *mlx);
int						ft_exit(int key, t_mlx *mlx);
t_point					*ft_get_point(int x, int y, char *str);
int						ft_cleaning(t_list **lst, t_map **map);
int						ft_line(int fd, t_list **list, int points);
t_map					*ft_get_map(int wd, int hg);
int						ft_fill_map(t_map **map, t_list *list);
int						ft_read_file(int fd, t_map **map);
t_mlx					*ft_create();
t_picture				*ft_del_picture(t_mlx *mlx, t_picture *pict);
t_picture				*ft_new_picture(t_mlx *mlx);
void					ft_beam_create(t_mlx *mlx, t_point f_point,
						t_point s_point);
int						ft_beam_of_point(t_mlx *mlx, t_beam *beam,
						t_point *f_point, t_point *s_point);
t_point					ft_rotate(t_point p, t_eyes *r);
t_point					ft_shift(t_map *map, int x, int y);
void					ft_clear_picture(t_picture *picture);
t_point					ft_project_point(t_point p, t_mlx *mlx);
void					ft_processing(t_mlx *mlx);
int						ft_press_button(int code, t_mlx *mlx);
int						ft_button_scale(int code, t_mlx *mlx);
void					ft_helper(void *mlx, void *window);
void					ft_pixel_color (t_mlx *mlx, int x, int y);
void					ft_epileptic(t_color *color);
int						ft_change_color(t_mlx *mlx);
void					ft_move_w(int key, t_mlx *mlx);

#endif
