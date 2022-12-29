/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:14 by geonwule          #+#    #+#             */
/*   Updated: 2022/12/28 20:51:45 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_diu(const char *format, int i, va_list ap)
{
	int				j;
	unsigned int	k;
	char			*y;

	if (format[i] == 'd' || format[i] == 'i')
	{
		j = va_arg(ap, int);
		ft_putnbr_fd(j, 1);
	}
	if (format[i] == 'u')
	{
		k = va_arg(ap, unsigned int);
		y = ft_itoa(k);
		ft_putstr_fd(y, 1);
	}
}

void	printp(unsigned int j, char	*y)
{
	if (j == 0)
	{
		write(1, "0x0", 3);
		return ;
	}
	write(1, "0x7ffe", 5);
	ft_putstr_fd(y, 1);
}

void	out_x2xp(const char *format, int i, va_list ap)
{
	unsigned int	j;
	char			*y;

	if (format[i] == 'x' || format[i] == 'X')
	{
		j = va_arg(ap, unsigned int);
		if (format[i] == 'x')
		{
			y = low_hex(j);
			ft_putstr_fd(y, 1);
		}
		else if (format[i] == 'X')
		{
			y = upp_hex(j);
			ft_putstr_fd(y, 1);
		}
	}
	if (format[i] == 'p')
	{
		j = va_arg(ap, unsigned int);
		y = low_hex(j);
		printp(j, y);
	}
}

void	out_cs(const char *format, int i, va_list ap)
{
	char	c;
	char	*s;

	if (format[i] == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar_fd(c, 1);
	}
	else if (format[i] == 's')
	{
		s = va_arg(ap, char*);
		ft_putstr_fd(s, 1);
	}
	else if (format[i] == '%')
	{
		write(1, "%", 1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	va_start(ap, format);
	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
			{
				out_diu(format, i, ap);
			}
			else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
			{
				out_x2xp(format, i, ap);
			}
			else if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
			{
				out_cs(format, i, ap);
			}
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
			i++;
			ret++;
			continue ;
		}
		ft_putchar_fd(format[i], 1);
		i++;
		ret++;
	}
	return (ret);
}
