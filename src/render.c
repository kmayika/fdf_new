/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:19:01 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 17:30:23 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	line(t_mlx *fdf_mlx, t_point pos)
{
	t_a a;

	a.dx = abs(pos.end_x - pos.start_x);
	a.dy = abs(pos.end_y - pos.start_y);
	a.sx = pos.start_x < pos.end_x ? 1 : -1;
	a.sy = pos.start_y < pos.end_y ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	while (2)
	{
		mlx_pixel_put(fdf_mlx->mlx, fdf_mlx->window,
				pos.start_x, pos.start_y, fdf_mlx->color);
		if (pos.start_x == pos.end_x && pos.start_y == pos.end_y)
			break ;
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			pos.start_x += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			pos.start_y += a.sy;
		}
	}
}

void	exchange(t_mlx *fdf_mlx)
{
	data_exchange(fdf_mlx);
}
