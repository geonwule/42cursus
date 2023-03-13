/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:13:49 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/13 18:50:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
