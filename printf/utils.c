/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:12:01 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/25 13:20:08 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len ++;
	return (len);
}*/

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	ft_putchar(nb % 10 + '0');
}

unsigned int	ft_nbr_len(int n)
{
	unsigned int	len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
	{
		len ++;
		nb = -n;
	}
	else
		nb = n;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len ++;
	}
	return (len);
}
