/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:08:14 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/05 11:57:16 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WD 1024
# define WIN_HG 800
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
#include <stdio.h>

typedef struct 	s_multi
{
	void	*multi;
	
}				t_multi;

typedef struct		s_pict
{
	void		*picture;
	char		*addr;
	int			bits_per_pixel;
	int			sz_line;
	int			endian;
}				t_pict;

typedef struct		s_color
{
	int r;
	int g;
	int b;
}					t_color;

typedef struct		s_mlx
{
	void	*mlx;
	void	*window;
	t_color	color;
	t_pict	*picture;
	double 	scale;
	int 	maxiter;
	int 	old_x;
	int		old_y;
	double	s_y;
	double	s_x;
	double	rl;
	double 	im;
	double 	hg;
	double 	hgg;
	double 	wd;
	int		fract;
}					t_mlx;

t_pict				*ft_new_picture(t_mlx *mlx);
t_mlx				*ft_start(void);
t_mlx				*ft_mlxdel(t_mlx *mlx);
int					ft_error(char *str);
int					ft_exit(int key, t_mlx *mlx);
int					ft_exit_x(void *par);
void				ft_helper();
void				ft_pixel_color(t_mlx *mlx, int x, int y, int n);
void				ft_multi_mandelbrot(t_mlx *mlx);
int					ft_press_button(int key, t_mlx *mlx);
void				*ft_julia(void *multi);
int					m_juli(int x, int y, t_mlx *mlx);
void				ft_multi_julia(t_mlx *mlx);
void				ft_begin(t_mlx *mlx);
void				ft_var(t_mlx *mlx);
int					ft_error(char *str);
void			 	ft_var(t_mlx *mlx);
int				 	ft_mouse(int c, int x, int y, t_mlx *mlx);
void				ft_rescale(t_mlx *mlx);

#endif
