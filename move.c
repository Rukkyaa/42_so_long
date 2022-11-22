/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:58:09 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/22 17:45:10 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	item_collect(t_vars *vars)
{
	printf("Item found %d/%d !\n", ++(vars->items), vars->item_total);
	vars->map[vars->y / 48][vars->x / 48] = '0';
}

void	put_current(t_vars *vars, char current)
{
	if (current == 'E' && vars->items != vars->item_total)
		put_img(vars, vars->image.exit_img, vars->x, vars->y);
	else if (current == 'P')
		put_img(vars, vars->image.start_img, vars->x, vars->y);
	else
		put_img(vars, vars->image.grass_img, vars->x, vars->y);
}

void	up(t_vars *vars)
{
	char	current;
	char	next;

	printf("Move : %d\n", ++vars->move);
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48 - 1][vars->x / 48];
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	if (next != '1')
	{
		put_current(vars, current);
		vars->y -= 48;
		if (next == 'E')
			put_img(vars, vars->image.dino_door_img, vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->image.dino_start_img, vars->x, vars->y);
		else
			put_dino(vars, vars->x, vars->y);
		if (next == 'C')
			item_collect(vars);
	}
}

void	down(t_vars *vars)
{
	char	current;
	char	next;

	printf("Move : %d\n", ++vars->move);
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48 + 1][vars->x / 48];
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	if (next != '1')
	{
		put_current(vars, current);
		vars->y += 48;
		if (next == 'E')
			put_img(vars, vars->image.dino_door_img, vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->image.dino_start_img, vars->x, vars->y);
		else
			put_dino(vars, vars->x, vars->y);
		if (next == 'C')
			item_collect(vars);
	}
}

void	left(t_vars *vars)
{
	char	current;
	char	next;

	printf("Move : %d\n", ++vars->move);
	vars->image.pos = "left";
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48][vars->x / 48 - 1];
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	if (next != '1')
	{
		put_current(vars, current);
		vars->x -= 48;
		if (next == 'E')
			put_img(vars, vars->image.dino_door_img, vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->image.dino_start_img, vars->x, vars->y);
		else
			put_dino(vars, vars->x, vars->y);
		if (next == 'C')
			item_collect(vars);
	}
}

void	right(t_vars *vars)
{
	char	current;
	char	next;

	printf("Move : %d\n", ++vars->move);
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48][vars->x / 48 + 1];
	vars->image.pos = "right";
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	if (next != '1')
	{
		put_current(vars, current);
		vars->x += 48;
		if (next == 'E')
			put_img(vars, vars->image.dino_door_img, vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->image.dino_start_img, vars->x, vars->y);
		else
			put_dino(vars, vars->x, vars->y);
		if (next == 'C')
			item_collect(vars);
	}
}
