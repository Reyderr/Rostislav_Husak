/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:25:39 by mpinson           #+#    #+#             */
/*   Updated: 2018/06/07 20:25:41 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define BITOVOCH 512
# define MIN_BIT 64
# define OCT 16
# define RIGHTROTATION(x, n) (((unsigned int)x >> n) | ((x << (32 - n))))
# define RIGHT_64_ROTATE(x, c) ((x >> c) | (x << (64 - c)))

# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_flag
{
	int				p_flag;
	int				q_flag;
	int				r_flag;
	uint32_t		s_flag;
}					t_flag;

typedef struct		s_sha_h
{
	uint32_t		hesh0;
	uint32_t		hesh1;
	uint32_t		hesh2;
	uint32_t		hesh3;

}					t_sha_h;

typedef struct		s_head
{
	uint32_t		heshes0;
	uint32_t		heshes1;
	uint32_t		heshes2;
	uint32_t		heshes3;
}					t_head;

typedef struct		s_block
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
}					t_block;

typedef struct		s_bl
{
	uint32_t		a1;
	uint32_t		b2;
	uint32_t		c3;
	uint32_t		d4;
	uint32_t		e5;
	uint32_t		f6;
}					t_bl;

typedef struct		s_dls
{
	uint32_t		*torl;
	uint32_t		*sys32;
}					t_dls;

typedef struct		s_ini
{
	int				next_l;
	int				bias;
	int				argc;
}					t_ini;

typedef struct		s_hs384
{
	uint64_t		s0;
	uint64_t		s1;
	uint64_t		zm;
	uint64_t		gs;
	uint64_t		tp;
	uint64_t		tps;

}					t_hs384;

typedef struct		s_hs512
{
	uint64_t		s0;
	uint64_t		s1;
	uint64_t		zm;
	uint64_t		gs;
	uint64_t		tp;
	uint64_t		tps;
}					t_hs512;

typedef struct		s_hesh
{
	t_flag			flags;
	t_head			head;
	t_sha_h			sha_h;
	t_block			block;
	t_bl			bl;
	t_dls			dls;
	t_ini			ini;
	int				type_hesh;
	int				ini_f;
	int				rost;
	int				fd;
	unsigned char	*input_line;
	char			*input_l;
}					t_hesh;

uint64_t			big_64_endian(uint64_t val);
uint64_t			ft_pop(uint64_t val, uint64_t shift1,
					uint64_t shift2, uint64_t shift3);
uint64_t			ft_pip(uint64_t val, uint64_t rot1,
					uint64_t rot2, uint64_t rot3);
uint32_t			ft_rev(uint32_t n);
uint64_t			ft_ris(uint64_t val, uint64_t shift1,
					uint64_t shift2, uint64_t shift3);
uint64_t			ft_zsg(uint64_t val, uint64_t rot1,
					uint64_t rot2, uint64_t rot3);

int					ft_f_dism(char **argv, t_hesh *hesh);
int					ft_delimer(int done, int num);
int					ft_no_s_flag(t_hesh *hesh, char **argv);
int					ft_st_md5(unsigned char *init_msg,
					size_t len, t_hesh *hesh);
int					ft_st_sha256(char *init_msg, size_t len, t_hesh *hesh);
int					ft_s_flag(char **argv, t_hesh *hesh, int argc);
int					ft_no_s_gflag(t_hesh *hesh, char **argv, int argc);
char				*ft_red_itoa32(uint32_t n);
char				*ft_red_itoa64(uint64_t ts);
char				*ft_red_itoa38(uint64_t ts);
char				*ft_freeing(char *line);
char				*ft_zero_inp(char *line);
void				ft_st_sha512(char *str);
void				ft_is_r_on(char **argv, t_hesh *hesh);
void				ft_sc_def_rot(char **argv, t_hesh *hesh);
void				ft_start(int argc, t_hesh *hesh, char **argv);
void				ft_type_n(char **argv, t_hesh *hesh);
void				ft_js_qs(int fd, t_hesh *hesh);
void				ft_start_md5(char *std, t_hesh *hesh);
void				ft_start_sha256(char *std, t_hesh *hesh);
void				ft_erro(int num_er);
void				ft_erro_comand(char *str);
void				ft_wrong(char *str);
void				ft_is_r_flag(t_hesh *hesh, char **argv);
void				ft_init(t_hesh *hesh);
void				ft_putdown(char **argv, t_hesh *hesh);
void				ft_initialaze(t_hesh *hesh);
void				ft_spo(t_hesh *hesh, size_t len);
void				ft_yop(t_hesh *hesh);
void				ft_de_ini(t_hesh *hesh);
void				ft_a1(t_hesh *hesh, int u);
void				ft_ini(t_hesh *hesh);
void				ft_bs_ini(t_hesh *hesh);
void				ft_compreh(t_hesh *hesh);
void				ft_ebro(t_hesh *hesh, char *s);
void				ft_rmbo(t_hesh *hesh, int num);
void				ft_ds(t_hs384 *hesh, uint64_t *message);
void				ft_error_init();
void				ft_start_sha512(char *std);
void				ft_adddls(char *c);
void				ft_st_sha384(char *str);
void				ft_start_sha384(char *std);
void				ft_hs(t_hs512 *hesh, uint64_t *message);
void				ft_vec_func(uint64_t val, uint64_t ts1, uint64_t ts2);

#endif
