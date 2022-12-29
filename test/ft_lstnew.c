
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//content : content to create the node with.
//return : new node
//malloc
//allocates and returns a new node. 
//member variable 'content' is initialized with the value of the 'content'.
//the variable 'next' is initialized th NULL
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
