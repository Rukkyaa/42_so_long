/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:07:00 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/25 15:52:39 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int flag)
{
	if (flag == 1)
		write(1, "Error\nInvalid map\n", 18);
	else if (flag == 2)
		write(1, "Error\nInvalid path\n", 19);
	else if (flag == 3)
		write(1, "Error\nInvalid name\n", 19);
}

int	main(int argc, char **argv, char **env)
{
	t_game	game;

	if (*env == 0)
		return (EXIT_FAILURE);
	if (argc != 2)
		return (EXIT_FAILURE);
	game.map = get_map(argv[1]);
	if (!game.map)
		return (EXIT_FAILURE);
	var_init(&game);
	map_init(&game);
	if (inondation(&game))
	{
		ft_error(2);
		close_window(&game);
	}
	mlx_hook(game.win, 2, 1L << 0, key_gestion, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
