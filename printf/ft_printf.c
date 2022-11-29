/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:40:38 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/14 10:28:02 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_list_init(t_print *list)
{
	list->len = 0;
	list->sharp = 0;
	list->plus = 0;
	list->field = 0;
	list->space = 0;
}

int	ft_printf(const char *format, ...)
{
	t_print			*list;
	unsigned int	i;

	i = 0;
	list = malloc(sizeof(t_print));
	if (!list)
		return (0);
	va_start(list->args, format);
	ft_list_init(list);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += print_param(list, format, i + 1);
		}
		else
			list->len += write(1, &format[i], 1);
		i ++;
	}
	va_end(list->args);
	i = list->len;
	free(list);
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	char const	*string = "Salut";
	char const	caractere = 'a';
	int const	number = -19284;
	unsigned int const	number_u = 2913;

	ft_printf("String : %s\n", string);
	ft_printf("Caractere : %c\n", caractere);
	ft_printf("Number : %d\n", number);
	ft_printf("Unsigned : %u\n", number_u);
	ft_printf("hexa : %x\n", 255);
	ft_printf("HEXA : %X\n", 255);
	ft_printf("%%d\n");
	ft_printf("Bonjour, je m'apelle %s et j'ai %d ans\n", "Alan", 48);
	ft_printf("%p\n", 9223372036854775807);
	ft_printf("%#10x\n", 8345934);
	ft_printf("\"%10d\"\n", 123456);
	ft_printf("%i", 1);
	return (0);
}
*/
