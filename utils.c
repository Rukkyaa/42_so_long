/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:54:15 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/22 13:26:07 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	var_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "so_long");
	vars->image.dinoright_img = mlx_xpm_file_to_image(vars->mlx, DINO_RIGHT,
			&vars->img_heigth, &vars->img_width);
	vars->image.dinoleft_img = mlx_xpm_file_to_image(vars->mlx, DINO_LEFT,
			&vars->img_heigth, &vars->img_width);
	vars->image.dino_door_img = mlx_xpm_file_to_image(vars->mlx, DINO_DOOR,
			&vars->img_heigth, &vars->img_width);
	vars->image.dino_start_img = mlx_xpm_file_to_image(vars->mlx, DINO_START,
			&vars->img_heigth, &vars->img_width);
	vars->image.wall_img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img_heigth, &vars->img_width);
	vars->image.grass_img = mlx_xpm_file_to_image(vars->mlx, GRASS,
			&vars->img_heigth, &vars->img_width);
	vars->image.cake_img = mlx_xpm_file_to_image(vars->mlx, CAKE,
			&vars->img_heigth, &vars->img_width);
	vars->image.exit_img = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&vars->img_heigth, &vars->img_width);
	vars->image.start_img = mlx_xpm_file_to_image(vars->mlx, START,
			&vars->img_heigth, &vars->img_width);
	vars->image.pos = "right";
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
	mlx_destroy_image(vars->mlx, vars->image.wall_img);
	mlx_destroy_image(vars->mlx, vars->image.dinoright_img);
	mlx_destroy_image(vars->mlx, vars->image.dinoleft_img);
	mlx_destroy_image(vars->mlx, vars->image.dino_door_img);
	mlx_destroy_image(vars->mlx, vars->image.dino_start_img);
	mlx_destroy_image(vars->mlx, vars->image.grass_img);
	mlx_destroy_image(vars->mlx, vars->image.cake_img);
	mlx_destroy_image(vars->mlx, vars->image.exit_img);
	mlx_destroy_image(vars->mlx, vars->image.start_img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_array(vars->map);
	exit(0);
}

void	put_img(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
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
