/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:54:15 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/25 13:58:46 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fail_xpm(t_game *game, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		mlx_destroy_image(game->mlx, game->texture[i]);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_array(game->map);
	exit(0);
}

void	*ft_open_xpm(t_game *game, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &game->img_size,
			&game->img_size);
	if (!img)
		fail_xpm(game, index);
	return (img);
}

void	img_init(t_game *game)
{
	game->texture[0] = ft_open_xpm(game, DINO_RIGHT_PATH, 0);
	game->texture[1] = ft_open_xpm(game, DINO_LEFT_PATH, 1);
	game->texture[2] = ft_open_xpm(game, DINO_DOOR_PATH, 2);
	game->texture[3] = ft_open_xpm(game, DINO_START_PATH, 3);
	game->texture[4] = ft_open_xpm(game, WALL_PATH, 4);
	game->texture[5] = ft_open_xpm(game, GRASS_PATH, 5);
	game->texture[6] = ft_open_xpm(game, CAKE_PATH, 6);
	game->texture[7] = ft_open_xpm(game, EXIT_PATH, 7);
	game->texture[8] = ft_open_xpm(game, START_PATH, 8);
	game->texture[9] = ft_open_xpm(game, WATER_PATH, 9);
}

int	key_gestion(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W)
		move(game, "up");
	else if (keycode == S)
		move(game, "down");
	else if (keycode == A)
		move(game, "left");
	else if (keycode == D)
		move(game, "right");
	return (0);
}
