/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:24:36 by geonwule          #+#    #+#             */
/*   Updated: 2022/12/28 19:27:14 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ret_len_cnt(unsigned int i)
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

char	*low_hex(unsigned int i)
{
	char	*hex;
	char	*ret;
	int		ret_len;

	hex = "0123456789abcdef";
	ret_len = ret_len_cnt(i);
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

char	*upp_hex(unsigned int i)
{
	char	*hex;
	char	*ret;
	int		ret_len;

	hex = "0123456789ABCDEF";
	ret_len = ret_len_cnt(i);
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
