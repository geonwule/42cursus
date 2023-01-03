/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:36:50 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/03 15:28:41 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = c;
	i = 0;
	if (d == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
