/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:35:49 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/03 15:51:01 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_len_check(int fd)
{
	char	c[1];
	int		len;

	len = 0;
	while (read(fd, c, 1))	//need error check
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*back_up;
	char		*dict;
	char		**ndict;
	int			line_len;

	line_len = line_len_check(fd);
	dict = (char *)malloc(sizeof(char) * (line_len + 1));
	if (dict == NULL)
		return (0);
	ndict = ft_split(dict, '\n');
	if (nothing read || error)
		return (NULL);

}
