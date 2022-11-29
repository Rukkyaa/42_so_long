/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:06:37 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/25 14:00:06 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_check_wall(char *map, int len)
{
	while (--len >= 0)
	{
		if (map[len] != '1')
			return (false);
	}
	return (true);
}

void	var_init(t_game *game)
{
	int const	x = ft_strlen(game->map[0]) * 48;
	int const	y = get_height(game->map) * 48;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	img_init(game);
	game->item_total = 0;
	game->items = 0;
	game->player.pos = "right";
	game->player.move = 0;
	game->player.x = 48;
	game->player.y = 48;
}

int	close_window(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 10)
		mlx_destroy_image(game->mlx, game->texture[i]);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_array(game->map);
	exit(0);
}
