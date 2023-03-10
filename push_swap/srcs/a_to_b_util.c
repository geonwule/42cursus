/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:14:16 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 17:07:16 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sort(t_list *node_a)
{
	long long	temp;
	int			i;

	i = 0;
	node_a = node_a->next;
	while (node_a)
	{
		temp = node_a->prev->content;
		if (temp > node_a->content)
			return (0);
		node_a = node_a->next;
	}
	return (1);
}

void	max_min_check(t_list *node, int *max, int *min)
{
	int	max_min[2];

	max_min[0] = node->content;
	max_min[1] = node->content;
	node = node->next;
	while (node)
	{
		if (max_min[0] < node->content)
			max_min[0] = node->content;
		if (max_min[1] > node->content)
			max_min[1] = node->content;
		node = node->next;
	}
	*max = max_min[0];
	*min = max_min[1];
}

void	b_to_a_f(int size, t_list **node_a, t_list **node_b, t_list **order)
{
	if (size <= 0)
		return ;
	if (size == 1)
	{
		ft_pa(node_a, node_b, order);
		return ;
	}
	if (size == 2)
	{
		if ((*node_b)->content <= (*node_b)->next->content)
			ft_sb(*node_b, order, 1);
		ft_pa(node_a, node_b, order);
		ft_pa(node_a, node_b, order);
		return ;
	}
}

void	a_to_b_f(int size, t_list **node_a, t_list **node_b, t_list **order)
{
	int		max_min[2];
	t_list	*temp;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*node_a)->content > (*node_a)->next->content)
			ft_sa(*node_a, order, 1);
		return ;
	}
	max_min_check(*node_a, &max_min[0], &max_min[1]);
	temp = *node_a;
	if (size == 3)
		t_size(max_min, node_a, order);
	else if (size == 4)
		f_size(max_min[1], node_a, node_b, order);
	else if (size == 5)
		ff_size(max_min[1], node_a, node_b, order);
}
