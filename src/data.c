/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:49:31 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 16:31:05 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	data_exchange(t_mlx *fdf_mlx)
{
	t_point pos;

	pos.start_x = fdf_mlx->x1;
	pos.end_x = fdf_mlx->x2;
	pos.start_y = fdf_mlx->y1;
	pos.end_y = fdf_mlx->y2;
	line(fdf_mlx, pos);
}
