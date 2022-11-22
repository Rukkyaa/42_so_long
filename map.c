/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:57:59 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/22 14:43:27 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_gen_texture(t_vars *vars, char c, int x, int y)
{
	if (c == '1')
		put_img(vars, vars->image.wall_img, x, y);
	else if (c == '0')
		put_img(vars, vars->image.grass_img, x, y);
	else if (c == 'C')
	{
		put_img(vars, vars->image.cake_img, x, y);
		vars->item_total++;
	}
	else if (c == 'E')
		put_img(vars, vars->image.exit_img, x, y);
	else if (c == 'P')
	{
		vars->x = x;
		vars->y = y;
		put_img(vars, vars->image.dino_start_img, x, y);
	}
}

void	map_init(t_vars *vars)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		x = 0;
		while (vars->map[i][++j])
		{
			map_gen_texture(vars, vars->map[i][j], x, y);
			x += vars->img_width;
		}
		y += vars->img_heigth;
	}
}

char	**get_map(char *arg)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(arg, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (NULL);
	map = fd_to_map(fd);
	if (!map)
		return (NULL);
	i = 0;
	if (!check_size(map) || !valid_content(map))
	{
		free_array(map);
		return (NULL);
	}
	return (map);
}
