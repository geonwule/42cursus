/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:08:18 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/11 18:29:35 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	char	*temp;
	int		flag;
	int		i;

	d = c;
	i = 0;
	flag = 0;
	if (d == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&s[i]);
	}
	while (s[i++] != '\0')
	{
		if (s[i] == d && ++flag > 0)
			temp = (char *)&s[i];
	}
	if (flag != 0)
		return (temp);
	return (0);
}
