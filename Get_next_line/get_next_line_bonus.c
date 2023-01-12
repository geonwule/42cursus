/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:08:22 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/12 11:08:28 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_txt(char *back, char **n_ptr, int *readsize, int fd)
{
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (0);
	*n_ptr = ft_strchr(back, '\n');
	while ((*n_ptr == NULL) && (*readsize != 0))
	{
		*readsize = read(fd, buf, BUFFER_SIZE);
		if (*readsize == -1)
		{
			free(back);
			free(buf);
			return (0);
		}
		if (*readsize == 0)
			break ;
		buf[*readsize] = '\0';
		back = ft_strjoin(back, buf);
		*n_ptr = ft_strchr(back, '\n');
	}
	free(buf);
	return (back);
}

char	*ret_set(char *back)
{
	char	*ret;
	int		i;

	i = 0;
	if (back[i] == '\0')
		return (0);
	while (back[i] != '\0')
	{
		if (back[i] == '\n')
			break ;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (ret == NULL)
		return (0);
	ft_strlcpy(ret, back, i + 2);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*back;
	char		*n_ptr;
	char		*ret;
	int			readsize;

	readsize = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	back = read_txt(back, &n_ptr, &readsize, fd);
	if (back == NULL)
		return (0);
	ret = ret_set(back);
	if (n_ptr != NULL)
		back = ft_strdup(n_ptr + 1, back);
	else if (readsize == 0)
	{
		free(back);
		back = 0;
	}
	return (ret);
}
