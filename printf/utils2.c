/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:21:39 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/09 09:25:07 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		n %= 10;
	}
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	len;

	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
		n %= len;
	}
	ft_putchar(base[n % len]);
}

unsigned int	ft_nbr_len_base(unsigned long n, char *base)
{
	unsigned int	len;
	unsigned int	len_base;

	len = 0;
	len_base = ft_strlen(base);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= len_base;
		len ++;
	}
	return (len);
}

unsigned int	ft_nbr_len_u(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	result;
	unsigned int	index;
	int				sign;

	result = 0;
	index = 0;
	sign = 1;
	while (nptr[index] == ' ' || (nptr[index] >= 9 && nptr[index] <= 13))
		index ++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign = -1;
		index ++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += nptr[index] - '0';
		index ++;
	}
	return (sign * result);
}
