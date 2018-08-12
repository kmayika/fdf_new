#include "../include/fdf.h"
/*static void	swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

static void	draw_line_part2(t_mlx *fdf_mlx, int **a, int **b, t_cords *cord)
{
	double	slope;
	double	offset;
	int		iterate;

	slope = 0;
	offset = 0;
	iterate = -1 + (2 * (cord->x1 < cord->x2));
	slope = ((double)abs(cord->y1 - cord->y2) / (double)abs(cord->x1
				- cord->x2)) * (-1 + (2 * (cord->y1 < cord->y2)));
	while (cord->x1 != cord->x2)
	{
		if (offset >= 0.49999 || offset <= -0.5)
		{
			offset -= -1 + (2 * (cord->y1 < cord->y2));
			cord->y1 += -1 + (2 * (cord->y1 < cord->y2));
		}
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, **a, **b, fdf_mlx->color);
		cord->x1 += iterate;
		offset += slope;
	}
}

void		ft_draw_line_sdl(t_mlx *fdf_mlx,int x1, int y1, int x2, int y2)
{
	int	*a;
	int	*b;
	t_cords cords;
	cords.x1 = x1;
	cords.y1 = y1;
	cords.y2 = y2;
	cords.x2 = x2;

	if (abs(cords.x1 - cords.x2) >= abs(cords.y1 - cords.y2))
	{
		a = &cords.x1;
		b = &cords.y1;
	}
	else
	{
		swap(&cords.x1, &cords.y1);
		swap(&cords.x2, &cords.y2);
		a = &cords.y1;
		b = &cords.x1;
	}
	draw_line_part2(fdf_mlx, &a, &b, &cords);
}*/

void	line(t_mlx *fdf_mlx, int start_x, int start_y, int end_x, int end_y)
{
	t_a		a;

	a.dx = abs(end_x - start_x);
	a.dy = abs(end_y - start_y);
	a.sx = start_x < end_x ? 1 : -1;
	a.sy = start_y < end_y ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	while (2)
	{
		mlx_pixel_put(fdf_mlx->mlx, fdf_mlx->window, start_x, start_y, 0x0000FF00);
		if (start_x == end_x && start_y == end_y)
			break ;
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			start_x += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			start_y += a.sy;
		}
	}
}
