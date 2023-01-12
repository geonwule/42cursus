/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:08:22 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/12 18:04:04 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*read_txt(t_list *lst, char **n_ptr, int readsize)
{
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (0);
	*n_ptr = ft_strchr(lst->content, '\n');
	while ((*n_ptr == NULL) && (readsize != 0))
	{
		readsize = read(lst->fd, buf, BUFFER_SIZE);
		if (readsize == -1)
		{
			free(lst->content);
			free(buf);
			return (0);
		}
		if (readsize == 0)
			break ;
		buf[readsize] = '\0';
		lst->content = ft_strjoin(lst->content, buf);
		*n_ptr = ft_strchr(lst->content, '\n');
	}
	free(buf);
	return (lst);
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


t_list	*ft_lstnew(char *content, int fd, t_list **head)
{
	t_list	*new;
	t_list	*prev;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->fd = fd;
	new->content = content;
	new->next = NULL;
	prev = *head;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (*head)
		*head = (*head)->next;
	*head = new;
	*head = prev;
	return (new);
}

void	lst_clear(t_list *lst, t_list **head, int fd)
{
	t_list	*temp1;

	if (lst->content)
		free(lst->content);
	while ((*head)->fd != fd)
		*head = (*head)->next;
	temp1 = (*head)->next;
	free(*head);
	*head = temp1;
}

char	*get_next_line(int fd)
{
	t_list			*lst;
	static t_list	*head;
	char			*n_ptr;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (0);
	lst = head;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (lst == NULL)
		lst = ft_lstnew(NULL, fd, &head);
	lst = read_txt(lst, &n_ptr, -1);
	if (lst->content == NULL)
	{
		free(lst);
		return (0);
	}
	ret = ret_set(lst->content);
	if (n_ptr != NULL)
		lst->content = ft_strdup(n_ptr + 1, lst->content);
	else
		lst_clear(lst, &head, fd);
	return (ret);
}

#include <stdio.h>
#include <fcntl.h>


int	main()
{
	int		fd;
	int		fd2;
	char	*gnl;
	char	*ret;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	int i = 2;
	printf("call num : %d\n", i);
	//1
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

	//2
	ret = get_next_line(fd2);
	printf("%s", ret);
	free(ret);
	//3
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	//4
	ret = get_next_line(fd2);
	printf("%s", ret);
	free(ret);

	//5
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	//6
	ret = get_next_line(fd2);
	printf("%s", ret);
	free(ret);
	system("leaks a.out");
	close(fd);
	close(fd2);
}
