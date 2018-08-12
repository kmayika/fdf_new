/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:36:57 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/08 12:23:26 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/fdf.h"
//#include<mlx.h>
#include<stdlib.h>

void lineBres (int x1, int y1, int x2, int y2, t_mlx *fdf_mlx)
 {
	int	x_end;
	int	y_end;
 	int dx = (x2 - x1), dy =(y2 - y1);
	int dx_abs = abs(dx), dy_abs = abs(dy);
 	int p_x = 2*dy - dx;
	int p_y = 2*dx - dy;
 	int twoDy = 2*dy_abs,twoDx = 2*dx_abs, twoDyMinusDx = 2 * (dy_abs - dx_abs);
 	int x, y;
	if (dy_abs <= dx_abs)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			x_end = x2;
		}
		else
		{
			x = x2;
			y = y2;
			x_end = x1;
		}
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, x, y,fdf_mlx->color);
		while (x < x_end)
		{
 			x++;
 			if (p_x < 0)
			{
 				p_x += twoDy;
			}
 			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y++;
				}
				else
				{
					y--;
				}
				p_x += twoDyMinusDx;
 			}
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, x, y,fdf_mlx->color);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			y_end = y2;
		}
		else
		{
			x = x2;
			y = y2;
			y_end = y1;
		}
		mlx_pixel_put(fdf_mlx, fdf_mlx->window,x,y,fdf_mlx->color);
		while (y < y_end)
		{
			y++;
			if (p_y <= 0)
			{
				p_y += twoDx;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x++;
				}
				else
				{
					x--;
				}
				p_y += twoDyMinusDx;
			}
			mlx_pixel_put(fdf_mlx, fdf_mlx->window, x,y, fdf_mlx->color);
		}
	}
 }
