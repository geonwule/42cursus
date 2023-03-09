/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:38:32 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/09 20:38:52 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	b_pivot(int size, t_list **node_a,
							t_list **node_b, t_list **order)
{
	long long	pivot;

	if (size <= 2)
	{
		b_to_a_f(size, node_a, node_b, order);
		return (NULL);
	}
	pivot = (((*node_b)->content + (*node_b)->next->content) / 2);
	if (pivot < 0 || (pivot == 0 && ((*node_b)->content < 0
				|| (*node_b)->next->content < 0)))
		pivot -= 1;
	return (pivot);
}

static int	sub_b(long long pivot, t_list **node_a,
					t_list **node_b, t_list **order)
{
	if ((*node_b)->content > pivot)
	{
		ft_rb(node_b, order, 1);
		return (1);
	}
	else
	{
		ft_pa(node_a, node_b, order);
		return (0);
	}
}

void	b_to_a(int size, t_list **node_a, t_list **node_b, t_list **order)
{
	long long	pivot;
	long long	rb_pa_c[2];
	int			i;
	int			temp;

	pivot = a_pivot(size, node_a, node_b, order);
	if (pivot == NULL)
		return ;
	rb_pa_c[0] = 0;
	rb_pa_c[1] = 0;
	i = 0;
	while (i++ < size)
	{
		temp = sub_b(pivot, node_a, node_b, order);
		if (temp)
			rb_pa_c[0]++;
		else
			rb_pa_c[1]++;
	}
	i = 0;
	while (i++ < rb_pa_c[0])
		ft_rrb(node_b, order, 1);
	a_to_b(rb_pa_c[1], node_a, node_b, order);
	b_to_a(rb_pa_c[0], node_a, node_b, order);
}
