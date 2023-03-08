/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:16:48 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/08 23:17:06 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **node, t_list **order, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (flag)
		ft_lstadd_back(order, ft_lstnew("rra", 0));
	if ((*node) == NULL || (*node)->next == NULL)
		return ;
	last = ft_lstlast(*node)->prev;
	temp = last->next;
	last->next = NULL;
	temp->prev = NULL;
	ft_lstadd_front(node, temp);
	*node = temp;
}

void	ft_rrb(t_list **node, t_list **order, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (flag)
		ft_lstadd_back(order, ft_lstnew("rrb", 0));
	if ((*node) == NULL || (*node)->next == NULL)
		return ;
	last = ft_lstlast(*node)->prev;
	temp = last->next;
	last->next = NULL;
	temp->prev = NULL;
	ft_lstadd_front(node, temp);
	*node = temp;
}

void	ft_rrr(t_list **node_a, t_list **node_b, t_list **order)
{
	ft_rra(node_a, order, 0);
	ft_rrb(node_b, order, 0);
	ft_lstadd_back(order, ft_lstnew("rrr", 0));
}