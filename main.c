/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:07:00 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/23 11:41:49 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

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
	t_vars	vars;

	if (*env == 0)
		return (0);
	if (argc != 2)
		return (EXIT_FAILURE);
	vars.map = get_map(argv[1]);
	if (!vars.map)
		return (EXIT_FAILURE);
	var_init(&vars);
	map_init(&vars);
	if (inondation(&vars))
	{
		ft_error(2);
		close_window(&vars);
	}
	mlx_hook(vars.win, 2, 1L << 0, key_gestion, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
