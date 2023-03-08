/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:14:16 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/08 23:46:15 by geonwule         ###   ########.fr       */
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

static void	max_min_check(t_list *node, long long *max, long long *min)
{
	long long	max_min[2];

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
	long long	max;
	long long	min;
	t_list		*temp;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*node_a)->content > (*node_a)->next->content)
			ft_sa(*node_a, order, 1);
		return ;
	}
	max_min_check(*node_a, &max, &min);
	temp = *node_a;
	if (size == 3)
	{
		if (already_sort(*node_a))
			return ;
		if ((*node_a)->content == max)
		{
			if ((*node_a)->next->content == min) // 2 -1 1
			{
				ft_rra(node_a, order, 1);
				ft_rra(node_a, order, 1);
			}
			else // 2 1 -1
			{
				ft_sa(*node_a, order, 1);
				ft_rra(node_a, order, 1);
			}
		}
		else if ((*node_a)->content == min) // -1 2 1
		{
			ft_rra(node_a, order, 1);
			ft_sa(*node_a, order, 1);
		}
		else
		{
			if (ft_lstlast(*node_a)->content == max) // 1 -1 2
				ft_sa(*node_a, order, 1);
			else // 1 2 -1
				ft_rra(node_a, order, 1);
		}
	}
	if (size == 4)
	{
		if (already_sort(*node_a))
			return ;
		if ((*node_a)->content == min) // '1' 2 3 4
			ft_pb(node_a, node_b, order);
		else if ((*node_a)->next->content == min) // 2 '1' 3 4
		{
			ft_sa(*node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		else if (ft_lstlast(*node_a)->content == min) // 2 3 4 '1'
		{
			ft_rra(node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		else // 2 3 '1' 4
		{
			ft_rra(node_a, order, 1);
			ft_rra(node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		a_to_b_f(3, node_a, node_b, order);
		ft_pa(node_a, node_b, order);
	}
	if (size == 5)
	{
		if ((*node_a)->content == min) // '1' 2 3 4 5
			ft_pb(node_a, node_b, order);
		else if ((*node_a)->next->content == min) // 2 '1' 3 4 5
		{
			ft_sa(*node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		else if ((*node_a)->next->next->content == min) // 2 3 '1' 4 5
		{
			ft_ra(node_a, order, 1);
			ft_sa(*node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		else if (ft_lstlast(*node_a)->content == min) // 2 3 4 5 '1'
		{
			ft_rra(node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		else // 2 3 4 '1' 5
		{
			ft_rra(node_a, order, 1);
			ft_rra(node_a, order, 1);
			ft_pb(node_a, node_b, order);
		}
		a_to_b_f(4, node_a, node_b, order);
		ft_pa(node_a, node_b, order);
	}
}