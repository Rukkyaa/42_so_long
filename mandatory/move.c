/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:58:09 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/25 14:02:20 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_current(t_game *game)
{
	int const	x = game->player.x;
	int const	y = game->player.y;

	if (game->player.current == 'E' && game->items != game->item_total)
		put_img(game, game->texture[EXIT_INDEX], x, y);
	else if (game->player.current == 'P')
		put_img(game, game->texture[START_INDEX], x, y);
	else
		put_img(game, game->texture[GRASS_INDEX], x, y);
}

void	edit_pos(t_game *game, char *direction)
{
	if (!strcmp(direction, "up"))
		game->player.y -= 48;
	else if (!strcmp(direction, "down"))
		game->player.y += 48;
	else if (!strcmp(direction, "left"))
	{
		game->player.x -= 48;
		game->player.pos = "left";
	}
	else if (!strcmp(direction, "right"))
	{
		game->player.x += 48;
		game->player.pos = "right";
	}
}

char	get_next(t_game *game, char *direction)
{
	if (!strcmp(direction, "up"))
		return (game->map[game->player.y / 48 - 1][game->player.x / 48]);
	else if (!strcmp(direction, "down"))
		return (game->map[game->player.y / 48 + 1][game->player.x / 48]);
	else if (!strcmp(direction, "left"))
		return (game->map[game->player.y / 48][game->player.x / 48 - 1]);
	else
		return (game->map[game->player.y / 48][game->player.x / 48 + 1]);
}

void	move(t_game *game, char *direction)
{
	char const	next = get_next(game, direction);
	int			x;
	int			y;

	game->player.current = game->map[game->player.y / 48][game->player.x / 48];
	if (next == 'E' && game->items == game->item_total)
		close_window(game);
	if (next != '1')
	{
		ft_printf("Moves : %d\n", ++game->player.move);
		put_current(game);
		edit_pos(game, direction);
		x = game->player.x;
		y = game->player.y;
		if (next == 'E')
			put_img(game, game->texture[DINO_DOOR_INDEX], x, y);
		else if (next == 'P')
			put_img(game, game->texture[DINO_START_INDEX], x, y);
		else
			put_dino(game, x, y);
		if (next == 'C')
			item_collect(game);
	}
}
