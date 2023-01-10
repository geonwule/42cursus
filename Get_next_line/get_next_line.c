/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:35:49 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/10 17:24:44 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_linked(t_list *origin)
{
	t_list	*temp;

	while (origin)
	{
		temp = origin;
		origin = origin->next;
		free(temp);
	}
}

t_list	*linked_set2(t_list *origin, int fd, int *readsize)
{
	char	buf[BUFFER_SIZE + 1];
	int		flag;

	flag = 0;
	while (1)
	{
		*readsize = read(fd, buf, BUFFER_SIZE);
		if (*readsize < 0 || (*readsize == 0 && flag == 0))
		{
			free_linked(origin);
			return (0);
		}
		if (*readsize == 0)
			break ;
		buf[*readsize] = '\0';
		ft_lstadd_back(&origin, ft_lstnew(ft_strdup(buf)));
		if (*readsize < BUFFER_SIZE)
			break ;
		flag++;
	}
	return (origin->next);
}

static char	*linked_set1(char *back, int fd, int *readsize)
{
	t_list	*origin;
	t_list	*origin_front;

	origin = ft_lstnew(NULL);
	origin_front = origin;
	origin = linked_set2(origin, fd, readsize);
	if (origin == NULL)
		return (0);
	back = origin->content;
	origin = origin->next;
	while (origin)
	{
		back = ft_strjoin(back, origin->content);
		origin = origin->next;
	}
	free_linked(origin_front);
	return (back);
}

char	*ret_set(char *back)
{
	char		*ret;
	static int	i;
	int			last_i;
	int			ori_i;

	ori_i = i;
	if (i >= (int)ft_strlen(back) || i == -1)
		return (0);
	while (back[i] != '\n' && back[i] != '\0')
		i++;
	if (back[i] == '\n' && back[i] != '\0')
		i++;
	last_i = i;
	ret = (char *)malloc(sizeof(char) * (i - ori_i + 1));
	if (ret == NULL)
		return (0);
	ret[i - ori_i] = '\0';
	while (--i - ori_i >= 0)
		ret[i - ori_i] = back[i];
	i = last_i;
	if (back[i] == '\0')
		i = -1;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		*back;
	static int		end;
	char			*ret;
	int				readsize;

	readsize = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || end > 0)
		return (0);
	back = linked_set1(back, fd, &readsize);
	if (back == NULL)
		return (0);
	ret = ret_set(back);
	if (ret == NULL)
	{
		free(back);
		end++;
	}
	if (readsize == -1)
	{
		free(back);
		back = 0;
	}
	return (ret);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	int		fd2;
	char	*gnl;
	char	*ret;

	fd = open("read_error.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);

	int i = 2;
	printf("call num : %d\n", i);
	//1
	ret = get_next_line(fd);
	printf("%s\n, p = %p\n", ret, ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	//2
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	ret = get_next_line(fd);
	printf("%s\n p = %p\n", ret, ret);
	free(ret);
	system("leaks a.out");
}
*/
/*
**char	*get_next_line(int fd)
{
	char	backup[100000];
	char	buf;
	char	*str;
	int		i;
	int		read_size;
	i = 0;
	while (1)
	{
		read_size = read(fd, &buf, 1);
		if (read_size < 0 || (read_size == 0 && buf == '\0'))
			return (0);
		if (read_size == 0)
			break ;
		backup[i] = buf;
		i++;
		if (buf == '\n')
			break ;
	}
	backup[i] = '\0';
	str = (char *)malloc(sizeof(char) * (i + 1));
	while (i >= 0)
	{
		str[i] = backup[i];
		i--;
	}
	return (str);
}*/
