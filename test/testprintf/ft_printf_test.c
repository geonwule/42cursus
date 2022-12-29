/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:14 by geonwule          #+#    #+#             */
/*   Updated: 2022/12/21 19:10:35 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


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
	else if (format[i] == 'u')
	{
		k = va_arg(ap, unsigned int);
		y = ft_utoa(k);
		ft_putstr_fd(y, 1);
	}
}

void	out_xXp(const char *format, int i, va_list ap)
{
	unsigned int	k;
	char			*y;

	if (format[i] == 'x')
	{
		k = va_arg(ap, unsigned int);
		y = ft_utoa(k);
		low_hex(y);	
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
				out_diu(format, i, ap);
			else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
				out_xXp(format, i, ap);
			else
			{
				write(1, "Error", 2);
			}
			i++;
			ret++;
			continue ;
		}
		ft_putchar_fd(format[i], 1);
		i++;
		ret++;
	}
	va_end(ap);
	return (ret);
}

int	main()
{
	printf("ft_print return value = %d\n",	ft_printf("hi %d %i %u \n", 42, -42, -10));
	printf("ft_print return value = %d\n",	ft_printf("hi %x\n", 17));
	// 0  -> hex : 00
	// 1  -> hex : 01
	// 9  -> hex : 09
	// 10 -> hex : 0a
	// 11 -> hex : 0b
	// 12 -> hex : 0c
	// 13 -> hex : 0d
	// 14 -> hex : 0e
	// 15 -> hex : 0f
	// 16 -> hex : 10
	// 17 -> hex : 11
	// ...
	// 31 -> hex : 1f
	// 32 -> hex : 20
}
