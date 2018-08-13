/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:40:09 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 14:28:12 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render_draw(t_mlx *fdf_mlx)
{
	fdf_mlx->pos_x = fdf_mlx->shift_x;
	fdf_mlx->pos_y = fdf_mlx->shift_y;
	ft_draw(fdf_mlx);
	fdf_mlx->pos_x = fdf_mlx->shift_x;
	fdf_mlx->pos_y = fdf_mlx->shift_y;
	ft_draw_x(fdf_mlx);
}

int		main(int ac, char **av)
{
	t_mlx *fdf_mlx;

	fdf_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ac == 2)
	{
		fdf_mlx->mlx = mlx_init();
		fdf_mlx->window = mlx_new_window(fdf_mlx->mlx,
				TILE_WIDTH, TILE_HEIGHT, "fdf");
		get_map(fdf_mlx, av[1]);
		fdf_mlx->space_x = SPACE_X;
		fdf_mlx->space_y = SPACE_Y;
		fdf_mlx->up_down_height = 1;
		fdf_mlx->shift_x = TILE_WIDTH / 2 / 2;
		fdf_mlx->shift_y = TILE_HEIGHT / 2;
		render_draw(fdf_mlx);
		mlx_key_hook(fdf_mlx->window, height, fdf_mlx);
		mlx_loop(fdf_mlx->mlx);
	}
	return (0);
}
