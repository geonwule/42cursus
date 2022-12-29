typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#include <stdlib.h>

void	del(void * dest)
{
	dest = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		del(temp->content);
		free(temp);
		temp = temp->next;
	}
	*lst = NULL;
}

void	addFirst(t_list *target, void *content)
{
	t_list	*newnode = malloc(sizeof(t_list));
	newnode->next = target->next;
	newnode->content = content;

	target->next = newnode;
}

#include <stdio.h>
int	main()
{
	t_list *head = malloc(sizeof(t_list));

	head->next = NULL;
	addFirst(head, (void *)10);
	addFirst(head, (void *)20);
	addFirst(head, (void *)30);
	
	t_list	*curr = head->next;
	ft_lstclear(&curr, &(del));
	while (curr != NULL)
	{
		printf("ok\n");
		printf("%d\n", (int)curr->content);
		curr = curr->next;
	}
}
