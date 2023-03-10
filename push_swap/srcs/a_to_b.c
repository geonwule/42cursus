/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:09:04 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 16:18:19 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	a_pivot(int size, t_list **node_a,
							t_list **node_b, t_list **order)
{
	long long	pivot;

	if (size <= 2)
	{
		a_to_b_f(size, node_a, node_b, order);
		return ((long long)INT_MAX + 1);
	}
	pivot = (((*node_a)->content + (*node_a)->next->content) / 2);
	if (pivot < 0 || (pivot == 0 && ((*node_a)->content < 0
				|| (*node_a)->next->content < 0)))
		pivot -= 1;
	return (pivot);
}

static int	sub_a(long long pivot, t_list **node_a,
					t_list **node_b, t_list **order)
{
	if ((*node_a)->content > pivot)
	{
		ft_ra(node_a, order, 1);
		return (1);
	}
	else
	{
		ft_pb(node_a, node_b, order);
		return (0);
	}
}

void	a_to_b(int size, t_list **node_a, t_list **node_b, t_list **order)
{
	long long	pivot;
	long long	ra_pb_c[2];
	int			i;
	int			temp;

	pivot = a_pivot(size, node_a, node_b, order);
	if (pivot == (long long)INT_MAX + 1)
		return ;
	ra_pb_c[0] = 0;
	ra_pb_c[1] = 0;
	i = 0;
	while (i++ < size)
	{
		temp = sub_a(pivot, node_a, node_b, order);
		if (temp)
			ra_pb_c[0]++;
		else
			ra_pb_c[1]++;
	}
	i = 0;
	while (i++ < ra_pb_c[0])
		ft_rra(node_a, order, 1);
	a_to_b(ra_pb_c[0], node_a, node_b, order);
	b_to_a(ra_pb_c[1], node_a, node_b, order);
}
