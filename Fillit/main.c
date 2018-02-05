/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:18:10 by rhusak            #+#    #+#             */
/*   Updated: 2018/01/17 12:28:30 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*input_map;
	int		i;
	t_tetra	*tetra;

	i = 0;
	if (argc != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	input_map = ft_read_map(fd);
	if (!ft_check_str(input_map))
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	tetra = ft_born_tetra(input_map);
	ft_solution(tetra);
	free(tetra);
	free(input_map);
	return (0);
}
