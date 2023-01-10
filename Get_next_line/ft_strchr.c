/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:43:32 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/10 17:54:04 by geonwule         ###   ########.fr       */
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

#include <stdio.h>

void	test_chr(char *s, char **p)
{
		*p = ft_strchr(s, ' ');
}

void	print_set(char *s, char *p)
{
	int	i = 0;
	while (s[i])
	{
		if (&s[i] == p)
			printf("%s\n", &s[i]);
		i++;
	}
}
int	main()
{
	char	*s = "42Seoul Shiitttt";
	char	*p;

	test_chr(s, &p);
	print_set(s, p);
}
