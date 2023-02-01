/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:35:53 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/16 15:43:38 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	error_mess(void)
{
	write(2, "Error\n", 6);
}

static int	check_cspdiux(const char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		return (1);
	else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
		return (1);
	else if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
		return (1);
	return (0);
}

int	error_check(const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (!check_cspdiux(format, i++))
			{
				error_mess();
				return (0);
			}
			continue ;
		}
		i++;
	}
	return (1);
}
