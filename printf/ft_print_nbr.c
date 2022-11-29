/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:01:58 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/14 10:21:21 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(t_print *list)
{
	int	n;

	n = va_arg(list->args, int);
	if (ft_nbr_len(n) < list->field)
		fill(list->field - ft_nbr_len(n), ' ');
	else if (list->plus && n >= 0)
	{
		list->len ++;
		ft_putchar('+');
	}
	else if (list->space && n >= 0)
	{
		list->len ++;
		ft_putchar(' ');
	}
	ft_putnbr(n);
	list->len += ft_nbr_len(n);
	if (list->field && ft_nbr_len(n) < list->field)
		list->len += list->field - ft_nbr_len(n);
}

void	ft_print_nbr_unsigned(t_print *list)
{
	unsigned int	n;

	n = va_arg(list->args, unsigned int);
	if (ft_nbr_len_u(n) < list->field)
		fill(list->field - ft_nbr_len_u(n), ' ');
	ft_putnbr_unsigned(n);
	list->len += ft_nbr_len_u(n);
	if (list->field > ft_nbr_len_u(n))
		list->len += list->field - ft_nbr_len_u(n);
}

void	ft_print_hex(t_print *list, char *base, char x)
{
	unsigned int	n;
	unsigned int	len_base;

	n = va_arg(list->args, unsigned int);
	len_base = ft_nbr_len_base(n, base);
	if (list->sharp && n && list->field >= 2)
		list->field -= 2;
	if (len_base < list->field)
		fill(list->field - len_base, ' ');
	if (list->sharp && n)
	{
		ft_putchar('0');
		ft_putchar(x);
		list->len += 2;
	}
	ft_putnbr_base(n, base);
	list->len += len_base;
	if (list->field > len_base)
		list->len += list->field - len_base;
}

void	ft_print_pointer(t_print *list, char *base)
{
	unsigned long	n;

	n = (long unsigned)va_arg(list->args, void *);
	if (n)
	{
		if (ft_nbr_len_base(n, base) < list->field)
			fill(list->field - ft_nbr_len_base(n, base), ' ');
		ft_putstr("0x");
		ft_putnbr_base(n, base);
		list->len += ft_nbr_len_base(n, base);
		list->len += 2;
	}
	else
	{
		ft_putstr("(nil)");
		list->len += 5;
	}
	if (list->field > ft_nbr_len_base(n, base))
		list->len += list->field - ft_nbr_len_base(n, base);
}
