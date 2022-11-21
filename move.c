/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:58:09 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/21 14:57:15 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	item_collect(t_vars *vars)
{
	printf("Item found %d/%d !\n", ++(vars->items), vars->item_total);
	vars->map[vars->y / 48][vars->x / 48] = '0';
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
	else if (next == 'E')
	{
		put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->y -= 48;
		put_img(vars, vars->dino_door_img, vars->x, vars->y);
	}
	else if (next != '1')
	{
		if (current == 'E' && vars->items != vars->item_total)
			put_img(vars, vars->exit_img, vars->x, vars->y);
		else
			put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->y -= 48;
		if (next == 'C')
			item_collect(vars);
		put_img(vars, vars->dino_img, vars->x, vars->y);
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
	else if (next == 'E')
	{
		put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->y += 48;
		put_img(vars, vars->dino_door_img, vars->x, vars->y);
	}
	else if (next != '1')
	{
		if (current == 'E' && vars->items != vars->item_total)
			put_img(vars, vars->exit_img, vars->x, vars->y);
		else
			put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->y += 48;
		if (next == 'C')
			item_collect(vars);
		put_img(vars, vars->dino_img, vars->x, vars->y);
	}
}

void	left(t_vars *vars)
{
	char	current;
	char	next;

	printf("Move : %d\n", ++vars->move);
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48][vars->x / 48 - 1];
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	else if (next == 'E')
	{
		put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->x -= 48;
		put_img(vars, vars->dino_door_img, vars->x, vars->y);
	}
	else if (next != '1')
	{
		if (current == 'E' && vars->items != vars->item_total)
			put_img(vars, vars->exit_img, vars->x, vars->y);
		else
			put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->x -= 48;
		if (next == 'C')
			item_collect(vars);
		put_img(vars, vars->dino_img, vars->x, vars->y);
	}
}

void	right(t_vars *vars)
{
	char	current;
	char	next;

	printf("Move : %d\n", ++vars->move);
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48][vars->x / 48 + 1];
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	else if (next == 'E')
	{
		put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->x += 48;
		put_img(vars, vars->dino_door_img, vars->x, vars->y);
	}
	else if (next != '1')
	{
		if (current == 'E' && vars->items != vars->item_total)
			put_img(vars, vars->exit_img, vars->x, vars->y);
		else
			put_img(vars, vars->grass_img, vars->x, vars->y);
		vars->x += 48;
		if (next == 'C')
			item_collect(vars);
		put_img(vars, vars->dino_img, vars->x, vars->y);
	}
}
