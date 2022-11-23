/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:54:15 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/23 11:46:55 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fail_xpm(t_vars *vars, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		mlx_destroy_image(vars->mlx, vars->texture[i]);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_array(vars->map);
	exit(0);
}

void	*ft_open_xpm(t_vars *vars, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path, &vars->img_heigth,
			&vars->img_width);
	if (!img)
		fail_xpm(vars, index);
	return (img);
}

void	img_init(t_vars *vars)
{
	vars->texture[0] = ft_open_xpm(vars, DINO_RIGHT_PATH, 0);
	vars->texture[1] = ft_open_xpm(vars, DINO_LEFT_PATH, 1);
	vars->texture[2] = ft_open_xpm(vars, DINO_DOOR_PATH, 2);
	vars->texture[3] = ft_open_xpm(vars, DINO_START_PATH, 3);
	vars->texture[4] = ft_open_xpm(vars, WALL_PATH, 4);
	vars->texture[5] = ft_open_xpm(vars, GRASS_PATH, 5);
	vars->texture[6] = ft_open_xpm(vars, CAKE_PATH, 6);
	vars->texture[7] = ft_open_xpm(vars, EXIT_PATH, 7);
	vars->texture[8] = ft_open_xpm(vars, START_PATH, 8);
	vars->texture[9] = ft_open_xpm(vars, WATER_PATH, 9);
}

void	var_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "so_long");
	img_init(vars);
	vars->pos = "right";
	vars->item_total = 0;
	vars->items = 0;
	vars->move = 0;
	vars->x = 48;
	vars->y = 48;
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 10)
		mlx_destroy_image(vars->mlx, vars->texture[i]);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_array(vars->map);
	exit(0);
}

int	key_gestion(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_window(vars);
	else if (keycode == W && vars->map[vars->y / 48 - 1][vars->x / 48] != '1')
		up(vars);
	else if (keycode == S && vars->map[vars->y / 48 + 1][vars->x / 48] != '1')
		down(vars);
	else if (keycode == A && vars->map[vars->y / 48][vars->x / 48 - 1] != '1')
		left(vars);
	else if (keycode == D && vars->map[vars->y / 48][vars->x / 48 + 1] != '1')
		right(vars);
	return (0);
}
