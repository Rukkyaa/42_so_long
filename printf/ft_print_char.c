/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:01:58 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/09 08:20:41 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *list)
{
	char	c;

	list->len ++;
	c = va_arg(list->args, int);
	ft_putchar(c);
}

void	ft_print_str(t_print *list)
{
	char	*str;

	str = va_arg(list->args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		list->len += 6;
	}
	else
	{
		ft_putstr(str);
		list->len += ft_strlen(str);
	}
}

void	ft_print_percent(t_print *list)
{
	ft_putchar('%');
	list->len ++;
}
