/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:06:30 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/02 15:11:19 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	point_ret_len_cnt(unsigned long i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		len++;
		i /= 16;
	}
	return (len);
}

char	*point_hex(unsigned long i)
{
	char	*hex;
	char	*ret;
	int		ret_len;

	hex = "0123456789abcdef";
	ret_len = point_ret_len_cnt(i);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	ret_len--;
	while (ret_len >= 0)
	{
		ret[ret_len] = hex[i % 16];
		i /= 16;
		ret_len--;
	}
	return (ret);
}
