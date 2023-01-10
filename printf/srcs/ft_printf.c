/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:14 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/02 15:29:36 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf2(const char *format, va_list ap, int i, int *ret)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
	{
		out_diu(format, i, ap, ret);
	}
	else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
	{
		out_x2xp(format, i, ap, ret);
	}
	else if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
	{
		out_cs(format, i, ap, ret);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
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
			if (!printf2(format, ap, i++, &ret))
				return (0);
			continue ;
		}
		ft_putchar_fd(format[i], 1);
		i++;
		ret++;
	}
	va_end(ap);
	return (ret);
}
