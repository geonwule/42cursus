#include <stdio.h>
#include "libft.h"

void	del(void *content)
{
	content = NULL;
}

void	all_f(void *content)
{
	content = "f";
}

int	main()
{
	t_list	*s;
	t_list	*temp;

	s = ft_lstnew("42Seoul");
	ft_lstadd_back(&s, ft_lstnew("hi"));
	ft_lstadd_back(&s, ft_lstnew("hello"));
	ft_lstadd_back(&s, ft_lstnew("good"));
	ft_lstadd_front(&s, ft_lstnew("why"));
	printf("lstsize = %d\n", ft_lstsize(s));

	ft_lstiter(s, &all_f);
	temp = s;
	while (s)
	{
		printf("%s\n", s->content);
		s = s->next;
	}
}
