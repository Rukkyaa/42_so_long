/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:29:24 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/25 12:57:56 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_dino(t_game *game, int x, int y)
{
	if (!strcmp(game->player.pos, "left"))
		put_img(game, game->texture[DINO_LEFT_INDEX], x, y);
	else if (!strcmp(game->player.pos, "right"))
		put_img(game, game->texture[DINO_RIGHT_INDEX], x, y);
}

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

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

void	fill_voisin(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		game->item_inond ++;
	if (map[y + 1][x] != '1' && map[y + 1][x] != '2')
	{
		map[y][x] = '2';
		fill_voisin(game, map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != '2')
	{
		map[y][x] = '2';
		fill_voisin(game, map, x, y - 1);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != '2')
	{
		map[y][x] = '2';
		fill_voisin(game, map, x + 1, y);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != '2')
	{
		map[y][x] = '2';
		fill_voisin(game, map, x - 1, y);
	}
	map[y][x] = '2';
}
