/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_f_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:05:19 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 17:07:02 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	t_sub(int *mm, t_list **node_a, t_list **order)
{
	if ((*node_a)->content == mm[1])
	{
		ft_rra(node_a, order, 1);
		ft_sa(*node_a, order, 1);
	}
	else
	{
		if (ft_lstlast(*node_a)->content == mm[0])
			ft_sa(*node_a, order, 1);
		else
			ft_rra(node_a, order, 1);
	}
}

void	t_size(int *mm, t_list **node_a, t_list **order)
{
	if (already_sort(*node_a))
		return ;
	if ((*node_a)->content == mm[0])
	{
		if ((*node_a)->next->content == mm[1])
		{
			ft_rra(node_a, order, 1);
			ft_rra(node_a, order, 1);
		}
		else
		{
			ft_sa(*node_a, order, 1);
			ft_rra(node_a, order, 1);
		}
	}
	else
		t_sub(mm, node_a, order);
}

void	f_size(int min, t_list **node_a, t_list **node_b, t_list **order)
{
	if (already_sort(*node_a))
		return ;
	if ((*node_a)->content == min)
		ft_pb(node_a, node_b, order);
	else if ((*node_a)->next->content == min)
	{
		ft_sa(*node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
	else if (ft_lstlast(*node_a)->content == min)
	{
		ft_rra(node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
	else
	{
		ft_rra(node_a, order, 1);
		ft_rra(node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
	a_to_b_f(3, node_a, node_b, order);
	ft_pa(node_a, node_b, order);
}

static void	ff_sub(int min, t_list **node_a, t_list **node_b, t_list **order)
{
	if (ft_lstlast(*node_a)->content == min)
	{
		ft_rra(node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
	else
	{
		ft_rra(node_a, order, 1);
		ft_rra(node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
}

void	ff_size(int min, t_list **node_a, t_list **node_b, t_list **order)
{
	if ((*node_a)->content == min)
		ft_pb(node_a, node_b, order);
	else if ((*node_a)->next->content == min)
	{
		ft_sa(*node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
	else if ((*node_a)->next->next->content == min)
	{
		ft_ra(node_a, order, 1);
		ft_sa(*node_a, order, 1);
		ft_pb(node_a, node_b, order);
	}
	else
		ff_sub(min, node_a, node_b, order);
	a_to_b_f(4, node_a, node_b, order);
	ft_pa(node_a, node_b, order);
}
