/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:42:43 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 17:30:19 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../get_next_line/libft/libft.h"
# include <fcntl.h>
# define TILE_WIDTH 1000
# define TILE_HEIGHT 1000
# define SPACE_Y 5
# define SPACE_X 5
# define SHIFT_Y 10
# define SHIFT_X 20
# define ISO_SHIFT_Y 10
# define ISO_SHIFT_X 1
# define HEIGHT up_down_height

typedef struct	s_mlx
{
	int			map[1024][1024];
	void		*mlx;
	char		*line;
	int			color;
	int			len;
	char		**coord;
	int			line_chars;
	int			colmn;
	void		*window;
	int			x;
	int			x1;
	int			x2;
	int			y;
	int			y1;
	int			y2;
	int			pos_x;
	int			pos_y;
	int			max_y;
	int			max_x;
	int			up_down_height;
	int			shift_x;
	int			shift_y;
	int			space_x;
	int			space_y;
	int			start_x;
	int			start_y;
}				t_mlx;

typedef struct	s_a
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_a;

typedef	struct	s_point
{
	int			end_x;
	int			start_y;
	int			start_x;
	int			end_y;
}				t_point;

void			get_map(t_mlx *mlx, char *str);
void			line(t_mlx *fdf_mlx, t_point pos);
void			ft_draw_x(t_mlx *fdf_mlx);
void			ft_draw(t_mlx *fdf_mlx);
void			render_draw(t_mlx *fdf_mlx);
int				height(int keycode, t_mlx *fdf_mlx);
void			data_exchange(t_mlx *fdf_mlx);
void			exchange(t_mlx *fdf);
#endif
