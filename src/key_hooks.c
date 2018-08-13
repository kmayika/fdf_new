/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:52:17 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 16:57:39 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(int keycode, t_mlx *fdf_mlx)
{
	if (keycode == 6)
	{
		fdf_mlx->space_x += 2;
		fdf_mlx->space_y += 2;
	}
	else if (keycode == 7)
	{
		fdf_mlx->space_y -= 2;
		fdf_mlx->space_x -= 2;
	}
}

int		height(int keycode, t_mlx *fdf_mlx)
{
	if (keycode == 126)
		fdf_mlx->shift_y -= 5;
	if (keycode == 53)
		exit(1);
	if (keycode == 123)
		fdf_mlx->shift_x -= 5;
	if (keycode == 124)
		fdf_mlx->shift_x += 5;
	if (keycode == 125)
		fdf_mlx->shift_y += 5;
	if (keycode == 13)
		fdf_mlx->up_down_height += 2;
	if (keycode == 14)
		fdf_mlx->up_down_height -= 2;
	if (keycode == 6 || keycode == 7)
		zoom(keycode, fdf_mlx);
	mlx_clear_window(fdf_mlx->mlx, fdf_mlx->window);
	render_draw(fdf_mlx);
	return (0);
}
