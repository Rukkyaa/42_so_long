/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:57:59 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/22 18:36:12 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

char	**dup_map(char **map)
{
	char		**dup;
	int const	height = get_height(map);
	int			i;

	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		dup[i] = strdup(map[i]);
		if (!dup[i])
			return (NULL);
	}
	dup[height] = 0;
	return (dup);
}

void	fill_voisin(t_vars *vars, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		vars->item_inond ++;
	if (map[y + 1][x] != '1' && map[y + 1][x] != '2')
	{
		map[y][x] = '2';
		fill_voisin(vars, map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != '2')
	{
		map[y][x] = '2';
		fill_voisin(vars, map, x, y - 1);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != '2')
	{
		map[y][x] = '2';
		fill_voisin(vars, map, x + 1, y);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != '2')
	{
		map[y][x] = '2';
		fill_voisin(vars, map, x - 1, y);
	}
//	put_img(vars, vars->image.water_img, x * 48, y * 48);
}

void	get_point(t_point *start, t_point *end, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				start->x = j;
				start->y = i;
			}
			else if (map[i][j] == 'E')
			{
				end->x = j;
				end->y = i;
			}
		}
	}
}

int	inondation(t_vars *vars)
{
	t_point	start;
	t_point	end;
	char	**dup;

	dup = dup_map(vars->map);
	if (!dup)
		return (0);
	vars->item_inond = 0;
	get_point(&start, &end, dup);
	fill_voisin(vars, dup, start.x, start.y);
	if (dup[end.y][end.x] == '2' && vars->item_total == vars->item_inond)
	{
		free_array(dup);
		return (0);
	}
	free_array(dup);
	return (1);
}

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
