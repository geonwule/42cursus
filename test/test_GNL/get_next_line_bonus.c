/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:08:22 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/12 12:40:52 by geonwule         ###   ########.fr       */
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
	static char	*back[257];
	char		*n_ptr;
	char		*ret;
	int			readsize;

	readsize = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	back[fd] = read_txt(back[fd], &n_ptr, &readsize, fd);
	if (back[fd] == NULL)
		return (0);
	ret = ret_set(back[fd]);
	if (n_ptr != NULL)
		back[fd] = ft_strdup(n_ptr + 1, back[fd]);
	else if (readsize == 0)
	{
		free(back[fd]);
		back[fd] = 0;
	}
	return (ret);
}

// #include <stdio.h>
// #include <fcntl.h>


// int	main()
// {
// 	int		fd;
// 	int		fd2;
// 	char	*gnl;
// 	char	*ret;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);

// 	int i = 2;
// 	printf("call num : %d\n", i);
// 	//1
// 	ret = get_next_line(fd);
// 	printf("%s", ret);
// 	free(ret);

// 	//2
// 	ret = get_next_line(fd2);
// 	printf("%s", ret);
// 	free(ret);
// 	//3
// 	ret = get_next_line(fd);
// 	printf("%s", ret);
// 	free(ret);
// 	//4
// 	ret = get_next_line(fd2);
// 	printf("%s", ret);
// 	free(ret);

// 	//5
// 	ret = get_next_line(fd);
// 	printf("%s", ret);
// 	free(ret);
// 	//6
// 	ret = get_next_line(fd2);
// 	printf("%s", ret);
// 	free(ret);
// //	system("leaks a.out");
// 	close(fd);
// 	close(fd2);
// }
