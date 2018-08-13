/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:55:44 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 13:23:57 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_split(char *str, t_mlx *mlx, int y)
{
	int		x;
	int		i;
	char	**line_tab;

	x = 0;
	i = 0;
	line_tab = ft_strsplit(str, ' ');
	while (line_tab[x] != NULL)
		x++;
	mlx->max_x = x;
	while (i < x)
	{
		mlx->map[y][i] = ft_atoi(line_tab[i]);
		i++;
	}
	while (x >= 1)
		ft_strdel(&line_tab[--x]);
	line_tab = NULL;
}

void	get_map(t_mlx *mlx, char *str)
{
	int		fd;
	char	*temp_line;
	int		y;

	y = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &temp_line) > 0)
	{
		ft_split(temp_line, mlx, y);
		y++;
		ft_strdel(&temp_line);
	}
	close(fd);
	mlx->max_y = y;
}
