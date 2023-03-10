/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:16:36 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 18:28:18 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **node, t_list **order, int flag)
{
	t_list	*temp;

	if (flag)
		ft_lstadd_back(order, ft_lstnew("ra", 0));
	if ((*node) == NULL || (*node)->next == NULL)
		return ;
	temp = *node;
	*node = (*node)->next;
	temp->next = NULL;
	(*node)->prev = NULL;
	ft_lstadd_back(node, temp);
}

void	ft_rb(t_list **node, t_list **order, int flag)
{
	t_list	*temp;

	if (flag)
		ft_lstadd_back(order, ft_lstnew("rb", 0));
	if ((*node) == NULL || (*node)->next == NULL)
		return ;
	temp = *node;
	*node = (*node)->next;
	temp->next = NULL;
	(*node)->prev = NULL;
	ft_lstadd_back(node, temp);
}

void	ft_rr(t_list **node_a, t_list **node_b, t_list **order)
{
	ft_ra(node_a, order, 0);
	ft_rb(node_b, order, 0);
	ft_lstadd_back(order, ft_lstnew("rr", 0));
}
