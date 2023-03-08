/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:16:07 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/08 23:16:13 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list *node, t_list **order, int flag)
{
	int	temp;

	if (node == NULL || node->next == NULL)
		return (0);
	temp = node->content;
	node->content = node->next->content;
	node->next->content = temp;
	if (flag)
		ft_lstadd_back(order, ft_lstnew("sa", 0));
	return (1);
}

int	ft_sb(t_list *node, t_list **order, int flag)
{
	int	temp;

	if (node == NULL || node->next == NULL)
		return (0);
	temp = node->content;
	node->content = node->next->content;
	node->next->content = temp;
	if (flag)
		ft_lstadd_back(order, ft_lstnew("sb", 0));
	return (1);
}

void	ft_ss(t_list *node_a, t_list *node_b, t_list **order)
{
	int	a;
	int	b;

	a = ft_sa(node_a, order, 0);
	b = ft_sb(node_b, order, 0);
	if (a && b)
		ft_lstadd_back(order, ft_lstnew("ss", 0));
}

void	ft_pa(t_list **node_a, t_list **node_b, t_list **order)
{
	t_list	*temp;

	ft_lstadd_back(order, ft_lstnew("pa", 0));
	if ((*node_b) == NULL)
		return ;
	temp = *node_b;
	(*node_b) = (*node_b)->next;
	temp->next = NULL;
	if (*node_b)
		(*node_b)->prev = NULL; // SEGV
	ft_lstadd_front(node_a, temp);
}

void	ft_pb(t_list **node_a, t_list **node_b, t_list **order)
{
	t_list	*temp;

	ft_lstadd_back(order, ft_lstnew("pb", 0));
	if ((*node_a) == NULL)
		return ;
	temp = *node_a;
	(*node_a) = (*node_a)->next;
	temp->next = NULL;
	if (*node_a)
		(*node_a)->prev = NULL; // SEGV
	ft_lstadd_front(node_b, temp);
}