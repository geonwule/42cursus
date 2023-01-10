#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"


t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

/*void	ft_lstadd_back(t_list **lst, t_list *new) // original
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	ft_lstlast(temp)->next = new;
}*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	t_list	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = new;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(const char) * ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	*ft_memset(void *dest, int value, size_t count)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		temp[i] = (unsigned char)value;
		i++;
	}
	return (dest);
}

/* original
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	str[s1_len + s2_len] = '\0';
	return (str);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i[2];

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (0);
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < s1_len)
		str[i[0]] = s1[i[0]];
	while (++i[1] < s2_len)
		str[i[0] + i[1]] = s2[i[1]];
	str[s1_len + s2_len] = '\0';
	return (str);
}

//#ifndef BUFFER_SIZE
//#define BUFFER_SIZE 5
//#endif

char	*ft_test(int fd)
{
	t_list	*origin;
	static char		*back;
	char			buf[BUFFER_SIZE + 1];
	int				readsize = 0;

	ft_memset(buf, 0, BUFFER_SIZE + 1);	// buf clear
	origin = ft_lstnew(NULL);
	while (1)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == -1)
			return (0);	//error
		if (readsize == 0)
			break ;	//EOF
		buf[BUFFER_SIZE] = '\0';
		ft_lstadd_back(&origin, ft_lstnew(ft_strdup(buf)));
		ft_memset(buf, 0, BUFFER_SIZE + 1);	// buf clear for while
		if (readsize < BUFFER_SIZE)
			break ;
	}
	if (readsize != 0)	//first loop back fill in
	{	
		back = origin->next->content;
		origin = origin->next->next;
		while (origin)
		{
			back = ft_strjoin(back, origin->content);
			origin = origin->next;
		}
	}
	char			*ret;
	static int	i = 0;
	int	last_i;
	while (back[i] == '\n')
		i++;
	int j = i;
	while (back[i] != '\n')
		i++;
	last_i = i;
	ret = (char *)malloc(sizeof(char) * (i - j + 1));
	if (ret == NULL)
		return (0);
	ret[i - j] = '\0';
	i--;
	while (i - j >= 0)
	{
		ret[i - j] = back[i];
		i--;
	}
	i = last_i;
	return (ret);
}



#include <limits.h>

// test.txt
/*
012345
good shooot
mammy
shot
bebe
*/
int	main()
{
	int fd = open("test.txt", O_RDONLY);

//	ft_test(fd);
	printf("%s", ft_test(fd));
	printf("%s", ft_test(fd));
	printf("%s", ft_test(fd));
	printf("%s", ft_test(fd));
	printf("%s", ft_test(fd));
	printf("%s", ft_test(fd));
}
