/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:05:29 by rhusak            #+#    #+#             */
/*   Updated: 2018/01/21 12:10:02 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_tetra
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_tetra	*next;
}					t_tetra;

char				*ft_read_map(int fd);
t_tetra				*ft_born_tetra(char *input_map);
void				ft_position_tetra(t_tetra **tetra, char *input_map);
int					ft_numb_tetra(char *input_map);
void				ft_print_map(char **map);
char				**ft_new_map(char **map, int size);
char				**ft_del_tetra(char **map, t_tetra *tetra, int size);
char				**ft_in_tetra(char **map, t_tetra *tetra, int size);
char				**ft_recursive(char **tetra_map, t_tetra *tetra, int size);
void				ft_solution(t_tetra *tetra);
int					ft_check_pos(char **map, t_tetra *tetra, int size);
int					ft_check_valid(char *stak, int k);
int					ft_check_link(char *stak, int k);
int					ft_check_str(char *stak);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putstr(char *str);
void				ft_putchar(char c);

#endif
