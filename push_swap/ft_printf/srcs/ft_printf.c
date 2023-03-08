/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:36:07 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/16 15:42:41 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sep_cspdiux(const char *format, va_list ap, int i, int *ret)
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
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	va_start(ap, format);
	i = 0;
	ret = 0;
	if (!error_check(format))
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			sep_cspdiux(format, ap, i++, &ret);
			continue ;
		}
		ft_putchar_fd(format[i], 1);
		i++;
		ret++;
	}
	va_end(ap);
	return (ret);
}
