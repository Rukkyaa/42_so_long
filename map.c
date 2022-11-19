/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:57:59 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/19 23:58:01 by rukkyaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (vars->map[i][j] == '1')
				put_img(vars, vars->wall_img, x, y);
			else if (vars->map[i][j] == '0')
				put_img(vars, vars->grass_img, x, y);
			else if (vars->map[i][j] == 'C')
			{
				put_img(vars, vars->cake_img, x, y);
				vars->item_total ++;
			}
			else if (vars->map[i][j] == 'E')
				put_img(vars, vars->exit_img, x, y);
			x += vars->img_width;
		}
		y += vars->img_heigth;
	}
	put_img(vars, vars->dino_img, vars->img_heigth, vars->img_width);
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
	printf("size : %d\n", check_size(map));
	while (map[i])
		printf("%s\n", map[i ++]);
	return (map);
}
