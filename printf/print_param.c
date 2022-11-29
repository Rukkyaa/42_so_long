/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:41:57 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/14 10:11:50 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_print *list)
{
	list->sharp = 0;
	list->plus = 0;
	list->space = 0;
	list->field = 0;
}

unsigned int	check_flags(t_print *list, const char *format,
	unsigned int index)
{
	unsigned int	i;

	i = 0;
	if (format[index] == '#' || format[index] == '+' || format[index] == ' ')
	{
		if (format[index] == '#')
			list->sharp = 1;
		else if (format[index] == '+')
			list->plus = 1;
		else if (format[index] == ' ')
			list->space = 1;
		i ++;
	}
	list->field += ft_atoi(format + index + i);
	if (list->field)
		i += ft_nbr_len(list->field);
	return (i);
}

void	fill(unsigned int nb, char c)
{
	while (nb--)
		ft_putchar(c);
}

unsigned int	print_param(t_print *list, const char *format,
	unsigned int index)
{
	unsigned int	i;

	i = check_flags(list, format, index);
	index += i;
	if (format[index] == 'c')
		ft_print_char(list);
	else if (format[index] == 's')
		ft_print_str(list);
	else if (format[index] == 'd' || format[index] == 'i')
		ft_print_nbr(list);
	else if (format[index] == 'u')
		ft_print_nbr_unsigned(list);
	else if (format[index] == 'x')
		ft_print_hex(list, "0123456789abcdef", 'x');
	else if (format[index] == 'X')
		ft_print_hex(list, "0123456789ABCDEF", 'X');
	else if (format[index] == '%')
		ft_print_percent(list);
	else if (format[index] == 'p')
		ft_print_pointer(list, "0123456789abcdef");
	ft_reset_flags(list);
	return (i + 1);
}
