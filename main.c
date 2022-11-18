/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:07:00 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/18 18:23:39 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <mlx.h>

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

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	aff_map(t_vars *vars)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		x = 0;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1')
			{
				vars->img = mlx_xpm_file_to_image(vars->mlx, WALL, &vars->dino_heigth,
					&vars->dino_width);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
			}
			x += vars->dino_width;
		}
		y += vars->dino_heigth;
	}
}

void	ft_square(t_vars *vars, int heigth, int width)
{
	int	i = -1;
	int	j = -1;

	while (++i < heigth)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(vars, i, j, 0x00FF0000);
	}
}

void	ft_fill(t_vars *vars, int color)
{
	int	i;
	int	j;

	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
		&vars->line_length, &vars->endian);
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGTH)
			my_mlx_pixel_put(vars, i, j, color);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	vars->img = mlx_xpm_file_to_image(vars->mlx, DINO, &vars->dino_heigth,
		&vars->dino_width);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	aff_map(vars);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_gestion(int keycode, t_vars *vars)
{
	printf("Keycode : %d\n", keycode);
	if (keycode == ESC)
		close_window(vars);
	else if (keycode == W && vars->map[vars->y / 48 - 1][vars->x / 48] != '1')
	{
		if (vars->y > 0)
			vars->y -= vars->dino_heigth;
		ft_fill(vars, 0x00F1C40F);
	}
	else if (keycode == S && vars->map[vars->y / 48 + 1][vars->x / 48] != '1')
	{
		if (vars->y < HEIGTH - vars->dino_heigth)
			vars->y += vars->dino_heigth;
		//ft_fill(vars, 0x00F1C40F);
		ft_fill(vars, 0x002ECC71);
	}
	else if (keycode == A && vars->map[vars->y / 48][vars->x / 48 - 1] != '1')
	{
		if (vars->x > 0)
			vars->x -= vars->dino_width;
		//ft_fill(vars, 0x00F1C40F);
		ft_fill(vars, 0x009B59B6);
	}
	else if (keycode == D && vars->map[vars->y / 48][vars->x / 48 + 1] != '1')
	{
		if (vars->x < WIDTH - vars->dino_width)
			vars->x += vars->dino_width;
		//ft_fill(vars, 0x00F1C40F);
		ft_fill(vars, 0x002E86C1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (EXIT_FAILURE);
	vars.map = get_map(argv[1]);
	if (!vars.map)
		return (EXIT_FAILURE);
	//free_array(map);

	vars.x = 48;
	vars.y = 48;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGTH, "Test");
	vars.img = mlx_xpm_file_to_image(vars.mlx, DINO, &vars.dino_width, &vars.dino_heigth);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x, vars.y);
	aff_map(&vars);
	mlx_key_hook(vars.win, key_gestion, &vars);
	//mlx_loop_hook(vars.mlx, key_gestion, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
