// lst = address node
// f : address of the function used to iterate on the list
// del : address funcion used to delete the content of a node if needed.
// return : new list , NULL if the allocation fails.
// malloc, free
// iterate f, each content, creates a new list
// resulting of the successive apllications of the function 'f',
// the del function is used to delete the content of a node if needed.
//

/*t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*curr;

	if (!lst || !f || !(result = ft_lstnew(f(lst->content))))
		return (0);
	curr = result;
	lst = lst->next;
	while (lst)
	{
		if (!(curr->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (result);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_front;

	if (!lst || !f)
		return (0);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (0);
	new_front = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->next)
		{
			ft_lstclear(&new_front, del);
			return (0);
		}
		lst = lst->next;
		new = new->next;
	}
	return (new_front);
}

/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	prev = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&prev, del);
			return (NULL);
		}
		ft_lstadd_back(&prev, new);
		new = new->next;
		lst = lst->next;
	}
	return (prev);
}*/
