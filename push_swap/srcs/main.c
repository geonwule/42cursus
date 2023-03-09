/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:13:49 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/09 20:07:13 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(int size, t_list **node_a, t_list **node_b, t_list **order)
{
	long long	x;
	long long	y;

	if (size <= 2)
	{
		a_to_b_f(size, node_a, node_b, order);
		return ;
	}
	long long pivot, ra_c = 0, pb_c = 0;
	x = (*node_a)->content;
	y = (*node_a)->next->content;
	pivot = ((x + y) / 2);
	if (pivot < 0 || (pivot == 0 && (x < 0 || y < 0)))
		pivot -= 1;
	for (int i = 0; i < size; i++)
	{
		if ((*node_a)->content > pivot)
		{
			ft_ra(node_a, order, 1);
			ra_c++;
		}
		else
		{
			ft_pb(node_a, node_b, order);
			pb_c++;
		}
	}
	for (int i = 0; i < ra_c; i++)
		ft_rra(node_a, order, 1);
	a_to_b(ra_c, node_a, node_b, order);
	b_to_a(pb_c, node_a, node_b, order);
}

void	b_to_a(int size, t_list **node_a, t_list **node_b, t_list **order)
{
	long long	x;
	long long	y;

	if (size <= 2)
	{
		b_to_a_f(size, node_a, node_b, order);
		return ;
	}
	long long pivot, rb_c = 0, pa_c = 0;
	x = (*node_b)->content;
	y = (*node_b)->next->content;
	pivot = ((x + y) / 2);
	if (pivot < 0 || (pivot == 0 && (x < 0 || y < 0)))
		pivot -= 1;
	pivot = (((*node_b)->content + (*node_b)->next->content) / 2);
	if (pivot <= 0)
		pivot -= 1;
	for (int i = 0; i < size; i++)
	{
		if ((*node_b)->content <= pivot)
		{
			ft_rb(node_b, order, 1);
			rb_c++;
		}
		else
		{
			ft_pa(node_a, node_b, order);
			pa_c++;
		}
	}
	for (int i = 0; i < rb_c; i++)
		ft_rrb(node_b, order, 1);
	a_to_b(pa_c, node_a, node_b, order);
	b_to_a(rb_c, node_a, node_b, order);
}

int	main(int ac, char **av)
{
	t_list	*node_a;
	t_list	*node_b;
	t_list	*order;
	int		size;

	node_a = NULL;
	node_b = NULL;
	order = NULL;
	if (check_error(&node_a, ac, av))
	{
		ft_printf("Error\n");
		return (0);
	}
	size = ft_lstsize(node_a);
	if (already_sort(node_a))
	{
		all_free(node_a, node_b, order);
		return (0);
	}
	if (size <= 5)
		a_to_b_f(size, &node_a, &node_b, &order);
	else
		a_to_b(size, &node_a, &node_b, &order);
	print_order(order);
	all_free(node_a, node_b, order);
}
