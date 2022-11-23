/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukkyaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:58:09 by rukkyaa           #+#    #+#             */
/*   Updated: 2022/11/23 11:28:01 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	put_current(t_vars *vars, char current)
{
	if (current == 'E' && vars->items != vars->item_total)
		put_img(vars, vars->texture[EXIT_INDEX], vars->x, vars->y);
	else if (current == 'P')
		put_img(vars, vars->texture[START_INDEX], vars->x, vars->y);
	else
		put_img(vars, vars->texture[GRASS_INDEX], vars->x, vars->y);
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
			put_img(vars, vars->texture[DINO_DOOR_INDEX], vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->texture[DINO_START_INDEX], vars->x, vars->y);
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
			put_img(vars, vars->texture[DINO_DOOR_INDEX], vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->texture[DINO_START_INDEX], vars->x, vars->y);
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
	vars->pos = "left";
	current = vars->map[vars->y / 48][vars->x / 48];
	next = vars->map[vars->y / 48][vars->x / 48 - 1];
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	if (next != '1')
	{
		put_current(vars, current);
		vars->x -= 48;
		if (next == 'E')
			put_img(vars, vars->texture[DINO_DOOR_INDEX], vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->texture[DINO_START_INDEX], vars->x, vars->y);
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
	vars->pos = "right";
	if (next == 'E' && vars->items == vars->item_total)
		close_window(vars);
	if (next != '1')
	{
		put_current(vars, current);
		vars->x += 48;
		if (next == 'E')
			put_img(vars, vars->texture[DINO_DOOR_INDEX], vars->x, vars->y);
		else if (next == 'P')
			put_img(vars, vars->texture[DINO_START_INDEX], vars->x, vars->y);
		else
			put_dino(vars, vars->x, vars->y);
		if (next == 'C')
			item_collect(vars);
	}
}
