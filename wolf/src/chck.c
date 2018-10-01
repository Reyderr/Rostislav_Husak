/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <rhusak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:30:22 by rhusak            #+#    #+#             */
/*   Updated: 2018/09/30 17:40:07 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void		ft_n_text(t_mlx *mlx)
{
	if (mlx->n_text != 1)
		mlx->n_text = 1;
	else
		mlx->n_text = 0;
}

void		ft_f_text(t_mlx *mlx)
{
	if (mlx->f_side != 1)
		mlx->f_side = 1;
	else
		mlx->f_side = 0;
}

void		ft_i(t_mlx *mlx)
{
	if (mlx->i_key != 1)
		mlx->i_key = 1;
	else
		mlx->i_key = 0;
}
