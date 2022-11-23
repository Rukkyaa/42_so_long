/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:19:21 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/23 10:21:07 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	item_collect(t_vars *vars)
{
	printf("Item found %d/%d !\n", ++(vars->items), vars->item_total);
	vars->map[vars->y / 48][vars->x / 48] = '0';
}

int	valid_name(char *map_name)
{
	char	**split;
	int		ret;
	int		height;

	split = ft_split(map_name, '.');
	if (!split)
		return (0);
	height = get_height(split) - 1;
	ret = (height > 0 && strcmp(split[height], "ber") == 0);
	free_array(split);
	return (ret);
}
