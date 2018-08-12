#include<mlx.h>
#include "../include/fdf.h"
#include<stdlib.h>

void	ft_split(char *str, t_mlx *mlx, int y)
{
	int	x = 0;
	int	i = 0;
	char	**line_tab;
	
	line_tab = ft_strsplit(str, ' ');//returns [0,0,10,10,0,0] from map
	while (line_tab[x] != NULL)
		x++;
	mlx->max_x = x;
	while (i < x)
	{
		mlx->map[y][i] = ft_atoi(line_tab[i]); //convert to number
		i++;
	}
}

void	get_map(t_mlx *mlx, char *str )
{
	int	fd;
	char	*temp_line;
	int	y = 0;
	
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &temp_line) > 0)
	{
		ft_split(temp_line, mlx, y);
		y++;
		free(temp_line);
	}
	close(fd);
	mlx->max_y = y;
}

int	height(int keycode, t_mlx *fdf_mlx)
{
	if (keycode == 126)
		fdf_mlx->shift_y -= 5;
	else if (keycode == 53)
		exit(1);
	else if (keycode == 123)
		fdf_mlx->shift_x -= 5;
	else if (keycode == 124)
		fdf_mlx->shift_x += 5;
	else if (keycode == 125)
		fdf_mlx->shift_y += 5;
	else if (keycode == 6)
		fdf_mlx->up_down_height += 2;
	else if (keycode == 7)
		fdf_mlx->up_down_height -= 2;
	else if (keycode == 13)
	{
		fdf_mlx->space_x += 5;
		fdf_mlx->space_y += 5;
	}
	else if (keycode == 14)
	{	fdf_mlx->space_y -= 5;
		fdf_mlx->space_x -= 5;
	}
	mlx_clear_window(fdf_mlx->mlx, fdf_mlx->window);
	render_draw(*fdf_mlx);
	return (0);
}

void 	ft_draw(t_mlx fdf_mlx)
{
	fdf_mlx.y = 0;
	fdf_mlx.color = 0x00FFFF;
	while (fdf_mlx.y < fdf_mlx.max_y)
	{
		fdf_mlx.x = 0;
		while (fdf_mlx.x < fdf_mlx.max_x)
		{
			fdf_mlx.x1 = fdf_mlx.pos_x + (fdf_mlx.x * fdf_mlx.space_x);
			fdf_mlx.y1 = fdf_mlx.pos_y - (fdf_mlx.x * fdf_mlx.space_y) - (fdf_mlx.map[fdf_mlx.y][fdf_mlx.x] * fdf_mlx.up_down_height);
			if (fdf_mlx.x == 0)
			{
				fdf_mlx.x2 = fdf_mlx.x1;
				fdf_mlx.y2 = fdf_mlx.y1;
			}
			line(&fdf_mlx, fdf_mlx.x1, fdf_mlx.y1, fdf_mlx.x2, fdf_mlx.y2);
			fdf_mlx.x2 = fdf_mlx.x1;
			fdf_mlx.y2 = fdf_mlx.y1;
			fdf_mlx.x++;
		}
		fdf_mlx.y++;
		fdf_mlx.pos_x += fdf_mlx.space_x;
		fdf_mlx.pos_y += fdf_mlx.space_y;
	}
}

void	ft_draw_x(t_mlx fdf_mlx)
{
	fdf_mlx.x = 0;
	fdf_mlx.color = 0x00FFFF;
	while (fdf_mlx.x < fdf_mlx.max_x)
	{
		fdf_mlx.y = 0;
		while (fdf_mlx.y < fdf_mlx.max_y)
		{
			fdf_mlx.x1 = fdf_mlx.pos_x + (fdf_mlx.y * fdf_mlx.space_x);
			fdf_mlx.y1 = fdf_mlx.pos_y + (fdf_mlx.y * fdf_mlx.space_y) - (fdf_mlx.map[fdf_mlx.y][fdf_mlx.x] *fdf_mlx.up_down_height);
			if (fdf_mlx.y == 0)
			{
				fdf_mlx.x2 = fdf_mlx.x1;
				fdf_mlx.y2 = fdf_mlx.y1;
			}
			line(&fdf_mlx, fdf_mlx.x1, fdf_mlx.y1, fdf_mlx.x2, fdf_mlx.y2);
			fdf_mlx.y++;
			fdf_mlx.x2 = fdf_mlx.x1;
			fdf_mlx.y2 = fdf_mlx.y1;
		}
		fdf_mlx.x++;
		fdf_mlx.pos_x += fdf_mlx.space_x;
		fdf_mlx.pos_y -= fdf_mlx.space_y;
	}
}
void	render_draw(t_mlx fdf_mlx)
{
	fdf_mlx.pos_x = fdf_mlx.shift_x;
	fdf_mlx.pos_y = fdf_mlx.shift_y;
	ft_draw(fdf_mlx);
	fdf_mlx.pos_x = fdf_mlx.shift_x;
	fdf_mlx.pos_y = fdf_mlx.shift_y;
	ft_draw_x(fdf_mlx);

}
int		main(int ac, char **av)
{
	t_mlx fdf_mlx;

	if (ac == 2)
	{
		fdf_mlx.mlx = mlx_init();
		fdf_mlx.window = mlx_new_window(fdf_mlx.mlx, TILE_WIDTH, TILE_HEIGHT, "fdf");
		get_map(&fdf_mlx, av[1]);
		fdf_mlx.space_x = 20;
		fdf_mlx.space_y = 20;
		fdf_mlx.shift_x = TILE_WIDTH/2/2;
		fdf_mlx.shift_y = TILE_HEIGHT/2;
		render_draw(fdf_mlx);
		mlx_key_hook(fdf_mlx.window, height, (t_mlx *)&fdf_mlx);
		mlx_loop(fdf_mlx.mlx);
	}
	return (0);
}
