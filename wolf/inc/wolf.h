/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:02:16 by rhusak            #+#    #+#             */
/*   Updated: 2018/10/01 15:40:55 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define WIN_WD 1024
# define WIN_HG 800
# define T_W 64
# define T_H 64
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

typedef struct		s_color
{
	int	r;
	int	g;
	int	b;
}					t_color;

typedef struct		s_map
{
	int			wd;
	int			hg;
	int			c;
	int			**sq;
	double		p_x;
	double		p_y;
	double		port1_x;
	double		port2_x;
	double		port1_y;
	double		port2_y;
}					t_map;

typedef struct		s_pict
{
	void		*picture;
	char		*addr;
	int			bits_per_pixel;
	int			sz_line;
	int			endian;
}					t_pict;

typedef struct		s_bottom
{
	double	b_x;
	double	b_y;
	double	way;
	double	w_w;
	double	p_way;
	double	wt;
	double	c_bot_x;
	double	c_bot_y;
	int		bot_tex_x;
	int		bot_tex_y;
}					t_bottom;

typedef struct		s_mlx
{
	t_pict		*picture;
	t_bottom	bot;
	t_map		*map;
	t_color		color;
	t_pict		texture[20];
	void		*background;
	void		*menu1;
	void		*menu2;
	void		*window;
	void		*mlx;
	double		d_x;
	double		d_y;
	double		od_x;
	double		pl_x;
	double		pl_y;
	double		o_pl_x;
	double		cam;
	double		rd_x;
	double		rd_y;
	double		s_dt_x;
	double		s_dt_y;
	double		d_dt_x;
	double		d_dt_y;
	double		mv_wall;
	double		x_w;
	int			iter_x;
	int			iter_y;
	int			touch;
	int			wall;
	int			line_hg;
	int			s_rend;
	int			e_rend;
	int			maus_x;
	int			oldm;
	int			lock;
	int			num;
	int			t_x;
	int			t_y;
	int			n_text;
	int			f_side;
	int			init;
	int			i_key;
	int			exit;
}					t_mlx;

t_mlx				*ft_starting(void);
t_pict				*ft_del_picture(t_mlx *mlx, t_pict *pic);
t_map				*ft_read_file(char *file);
void				ft_wolf(t_mlx *mlx);
void				ft_draw(t_mlx *mlx, int x);
void				ft_calc(t_mlx *mlx);
void				ft_command(void);
void				ft_swap(t_map *m, int x, int y);
void				ft_move_arrow(int key, t_mlx *mlx);
void				ft_chtexture(t_mlx *mlx);
void				ft_begin(t_mlx *mlx);
void				ft_start_screen(t_mlx *mlx);
void				ft_check_p(t_map *m, int y, int x);
void				ft_rend_screen(t_mlx *mlx);
void				ft_chtexture(t_mlx *mlx);
void				ft_rend_screen(t_mlx *mlx);
void				ft_f_text(t_mlx *mlx);
void				ft_wall(t_mlx *mlx);
void				ft_wall_0(t_mlx *mlx);
void				ft_i(t_mlx *mlx);
void				ft_calc_bot_top(t_mlx *mlx, int y);
void				ft_n_text(t_mlx *mlx);
void				ft_convert(t_mlx *mlx, char *name, int i);
void				ft_lock(t_mlx *mlx);
void				ft_r_texture1(char **texture, t_mlx *mlx);
void				ft_menu(t_mlx *mlx, int a, int b);
void				ft_r_texture2(char **texture, t_mlx *mlx);
void				ft_move_db(int key, t_mlx *mlx);
void				ft_move_rl(int key, t_mlx *mlx);
int					ft_man(t_map *m, char **split, int x, int y);
int					ft_exit(int key, t_mlx *mlx);
int					ft_exit_x(void *par);
int					ft_button_pressig(int key, t_mlx *mlx);
int					ft_maus(int x, int y, t_mlx *mlx);
int					ft_strcol(char *str, char *color);
int					ft_f_side(t_mlx *mlx);
int					ft_side(t_mlx *mlx);
t_map				*populate_map(t_map *m, t_list *list);

#endif
