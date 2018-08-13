/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:36:57 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 17:30:26 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_draw(t_mlx *fdf_mlx)
{
	fdf_mlx->y = 0;
	fdf_mlx->color = 0x00FF00;
	while (fdf_mlx->y < fdf_mlx->max_y)
	{
		fdf_mlx->x = 0;
		while (fdf_mlx->x < fdf_mlx->max_x)
		{
			fdf_mlx->x1 = fdf_mlx->pos_x + (fdf_mlx->x * fdf_mlx->space_x);
			fdf_mlx->y1 = fdf_mlx->pos_y - (fdf_mlx->x * fdf_mlx->space_y) -
			(fdf_mlx->map[fdf_mlx->y][fdf_mlx->x] * fdf_mlx->up_down_height);
			if (fdf_mlx->x == 0)
			{
				fdf_mlx->x2 = fdf_mlx->x1;
				fdf_mlx->y2 = fdf_mlx->y1;
			}
			exchange(fdf_mlx);
			fdf_mlx->x2 = fdf_mlx->x1;
			fdf_mlx->y2 = fdf_mlx->y1;
			fdf_mlx->x++;
		}
		fdf_mlx->y++;
		fdf_mlx->pos_x += fdf_mlx->space_x;
		fdf_mlx->pos_y += fdf_mlx->space_y;
	}
}

void	ft_draw_x(t_mlx *fdf_mlx)
{
	fdf_mlx->x = 0;
	fdf_mlx->color = 0x00FF00;
	while (fdf_mlx->x < fdf_mlx->max_x)
	{
		fdf_mlx->y = 0;
		while (fdf_mlx->y < fdf_mlx->max_y)
		{
			fdf_mlx->x1 = fdf_mlx->pos_x + (fdf_mlx->y * fdf_mlx->space_x);
			fdf_mlx->y1 = fdf_mlx->pos_y + (fdf_mlx->y * fdf_mlx->space_y) -
			(fdf_mlx->map[fdf_mlx->y][fdf_mlx->x] * fdf_mlx->up_down_height);
			if (fdf_mlx->y == 0)
			{
				fdf_mlx->x2 = fdf_mlx->x1;
				fdf_mlx->y2 = fdf_mlx->y1;
			}
			exchange(fdf_mlx);
			fdf_mlx->y++;
			fdf_mlx->x2 = fdf_mlx->x1;
			fdf_mlx->y2 = fdf_mlx->y1;
		}
		fdf_mlx->x++;
		fdf_mlx->pos_x += fdf_mlx->space_x;
		fdf_mlx->pos_y -= fdf_mlx->space_y;
	}
}
