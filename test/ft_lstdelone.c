typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#include <stdlib.h>
// lst : the node to free.
// del : the address of the function used to delete the content.
// external funct : free
// des : takes as a parameter a node and frees the memory of the node's content using
// the function 'del' given as a parameter and free the node.
// the memory of 'next' must not be freed.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	temp = lst->next;
	lst->next = temp->next;
	del(lst);
//	del(lst->content);
//	free(lst);
//	lst = temp;
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
	ft_lstdelone(curr, &(free));
	while (curr != NULL)
	{
		printf("%d\n", (int)curr->content);
		curr = curr->next;
	}
}
