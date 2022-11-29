/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:29:48 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/14 10:29:41 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list			args;
	unsigned int	len;
	unsigned int	sharp;
	unsigned int	plus;
	unsigned int	space;
	unsigned int	field;
}				t_print;

int				ft_printf(const char *format, ...);
unsigned int	print_param(t_print *list, const char *format,
					unsigned int index);
void			ft_reset_flags(t_print *list);
unsigned int	check_flags(t_print *list, const char *format,
					unsigned int index);
void			fill(unsigned int nb, char c);

void			ft_print_char(t_print *list);
void			ft_print_str(t_print *list);
void			ft_print_nbr(t_print *list);
void			ft_print_nbr_unsigned(t_print *list);
void			ft_print_hex(t_print *list, char *base, char x);
void			ft_print_percent(t_print *list);
void			ft_print_pointer(t_print *list, char *base);

void			ft_putchar(char c);
size_t			ft_strlen(char *s);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
unsigned int	ft_nbr_len(int n);

void			ft_putnbr_unsigned(unsigned int n);
void			ft_putnbr_base(unsigned long n, char *base);
unsigned int	ft_nbr_len_base(unsigned long n, char *base);
unsigned int	ft_nbr_len_u(unsigned int n);
int				ft_atoi(const char *nptr);

#endif
