
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


// lst : address of a pointer to the first link of a list
// new : address of a pointer to the node to be added to the list.
// des : adds the node 'new' at the beginning of the list.
void ft_lstadd_front(t_list **lst, t_list *new);
{
	if (new->content == NULL)
		return ;
	else if (lst->content == NULL)
	{
		*lst = new;
		return ;
	}
	new->next->content = lst->content;
	*lst = new;
}

// lst-> content lst->next->content lst->next->next = NULL
