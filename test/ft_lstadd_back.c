#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (*lst)
	{
		temp = *lst;
		*lst = *lst->next; // rror: member reference base type 't_list *' (aka 'struct s_list *') is not a structure or union
//                *lst = *lst->next;
//                      ~~~^ ~~~~
	}
	temp->next = new;
}
