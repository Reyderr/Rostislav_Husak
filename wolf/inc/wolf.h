/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:02:16 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/21 11:29:01 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define WIN_WD 1024
# define WIN_HG 800
# define END "\033[0m"
# define RED "\033[31m"
# define WHITE "\033[0;37m"
# define BLACK "\033[0;30m"
# define GREY "\033[37m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define LIGT_BLUE "\033[0;36m"
# define AQUAMARINE "\033[36m"
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct 			s_color 
{
	int	r;
	int	g;
	int	b;
}						t_color;

typedef	struct			s_map
{
	int			wd;
	int			hg;
	double		p_x;
	double		p_y;
	int			**sq;
}						t_map;

typedef struct		s_pict
{
	void		*picture;
	char		*addr;
	int		bits_per_pixel;
	int		sz_line;
	int		endian;
}					t_pict;

typedef struct		s_mlx
{
	t_pict		*picture;
	t_map		*map;
	t_color	color;
	void		*window;
	void		*mlx;
	double	d_x;
	double	d_y;
	double	od_x;
	double	pl_x;
	double	pl_y;
	double	o_pl_x;
	double	cam;
	double	rd_x;
	double	rd_y;
	double	s_dt_x;
	double	s_dt_y;
	double	d_dt_x;
	double	d_dt_y;
	double	mv_wall;
	int		iter_x;
	int		iter_y;
	int		touch;
	int		wall;
	int		line_hg;
	int		s_rend;
	int		e_rend;
	int		maus_x;
	int		oldm;
	int		lock;
	int		*texture;
}			t_mlx;


t_mlx		*ft_starting(void);
void		ft_draw(t_mlx *mlx, int x);
t_map		*ft_read_file(char *file);
void		ft_wolf(t_mlx *mlx);
int		ft_exit(int key, t_mlx *mlx);
int		ft_exit_x(void *par);
int		ft_button_pressig(int key, t_mlx *mlx);
void		ft_calc(t_mlx *mlx);
void		ft_color_set(t_mlx *mlx, int r, int g, int b);
void		ft_move_arrow(int key, t_mlx *mlx);
int		ft_maus(int x, int y, t_mlx *mlx);

#endif
