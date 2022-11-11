/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:31 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/11 18:31:55 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	needle_check(const char *str, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[i + j] == nee[j]) && nee[j] != '\0' && j < len)
			j++;
		if (j == len)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;

	index = needle_check(haystack, needle, len);
	if (needle[0] == '\0' || len == 0)
		return ((char *)haystack);
	if (!index)
		return (0);
	return ((char *)&haystack[index]);
}
