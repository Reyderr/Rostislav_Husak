/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:08:14 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/08 14:57:06 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
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
# include <pthread.h>
# include <fcntl.h>

typedef struct		s_pict
{
	void		*picture;
	char		*addr;
	int			bits_per_pixel;
	int			sz_line;
	int			endian;
}					t_pict;

typedef struct		s_color
{
	int r;
	int g;
	int b;
}					t_color;

typedef struct		s_mlx
{
	t_color	color;
	t_pict	*picture;
	void	*mlx;
	void	*window;
	double	scale;
	double	dx;
	double	dy;
	double	tmp;
	double	z_r;
	double	z_i;
	double	iter;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	interpolation;
	double	move_x;
	double	move_y;
	double	s_y;
	double	s_x;
	double	rl;
	double	im;
	double	hg;
	double	hgg;
	double	wd;
	int		maxiter;
	int		fract;
	int		lock;
	int		rd;
	int		gr;
	int		bl;
}					t_mlx;

t_pict				*ft_del_picture(t_mlx *mlx, t_pict *pic);
t_pict				*ft_new_picture(t_mlx *mlx);
t_mlx				*ft_start(void);
t_mlx				*ft_mlxdel(t_mlx *mlx);
int					ft_error(char *str);
int					ft_exit(int key, t_mlx *mlx);
int					ft_exit_x(void *par);
int					ft_press_button(int key, t_mlx *mlx);
int					m_juli(int x, int y, t_mlx *mlx);
int					ft_error(char *str);
int					ft_error(char *str);
int					ft_mouse(int c, int x, int y, t_mlx *mlx);
void				ft_epileptic(t_mlx *mlx);
void				ft_b_spider(t_mlx *mlx);
void				ft_b_bship(t_mlx *mlx);
void				ft_rand_col(int key, t_mlx *mlx);
void				ft_iterations(int key, t_mlx *mlx);
void				ft_var(t_mlx *mlx);
void				ft_lock(t_mlx *mlx);
void				ft_choise(int key, t_mlx *mlx);
void				ft_rescale(t_mlx *mlx);
void				ft_multi_mandelbrot(t_mlx *mlx);
void				ft_multi_julia(t_mlx *mlx);
void				ft_multi_liambda(t_mlx *mlx);
void				ft_multi_bship(t_mlx *mlx);
void				ft_multi_spider(t_mlx *mlx);
void				ft_str(t_mlx *mlx);
void				ft_helper();
void				ft_pixel_color(t_mlx *mlx, int x, int y, int n);
void				ft_begin(t_mlx *mlx);
void				ft_var(t_mlx *mlx);

#endif
