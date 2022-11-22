/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:29:24 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/22 11:39:19 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_dino(t_vars *vars, int x, int y)
{
	if (!strcmp(vars->image.pos, "left"))
		put_img(vars, vars->image.dinoleft_img, x, y);
	else if (!strcmp(vars->image.pos, "right"))
		put_img(vars, vars->image.dinoright_img, x, y);
}
