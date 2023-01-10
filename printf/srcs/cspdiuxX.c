/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiuxX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:24:22 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/02 15:29:21 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_diu(const char *format, int i, va_list ap, int *ret)
{
	int				j;
	unsigned int	k;
	char			*y;

	if (format[i] == 'd' || format[i] == 'i')
	{
		j = va_arg(ap, int);
		y = ft_itoa(j);
	}
	if (format[i] == 'u')
	{
		k = va_arg(ap, unsigned int);
		y = ft_utoa(k);
	}		
	*ret += ft_strlen(y);
	ft_putstr_fd(y, 1);
	free(y);
}

void	printp(unsigned long k, char	*y, int *ret)
{
	if (k == 0)
	{
		write(1, "0x0", 3);
		*ret += 3;
		return ;
	}
	write(1, "0x", 2);
	*ret += 2;
	*ret += ft_strlen(y);
	ft_putstr_fd(y, 1);
}

void	out_x2xp(const char *format, int i, va_list ap, int *ret)
{
	unsigned int	j;
	char			*y;
	unsigned long	k;

	if (format[i] == 'x' || format[i] == 'X')
	{
		j = va_arg(ap, unsigned int);
		if (format[i] == 'x')
			y = low_hex(j);
		if (format[i] == 'X')
			y = upp_hex(j);
		*ret += ft_strlen(y);
		ft_putstr_fd(y, 1);
		free(y);
	}
	if (format[i] == 'p')
	{
		k = va_arg(ap, unsigned long);
		y = point_hex(k);
		printp(k, y, ret);
		free(y);
	}
}

void	out_s(va_list ap, int *ret)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	ft_putstr_fd(s, 1);
	*ret += ft_strlen(s);
}

void	out_cs(const char *format, int i, va_list ap, int *ret)
{
	char	c;

	if (format[i] == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar_fd(c, 1);
		*ret += 1;
	}
	else if (format[i] == 's')
		out_s(ap, ret);
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		*ret += 1;
	}
}
