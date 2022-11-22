/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:07:00 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/22 18:36:01 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (EXIT_FAILURE);
	vars.map = get_map(argv[1]);
	if (!vars.map)
		return (EXIT_FAILURE);
	var_init(&vars);
	map_init(&vars);
	if (inondation(&vars))
		close_window(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_gestion, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
