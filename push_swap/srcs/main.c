/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:13:49 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/11 17:26:30 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars->node_a = NULL;
	vars->node_b = NULL;
	vars->order = NULL;
	if (check_error(vars->node_a, ac, av))
	{
		ft_printf("Error\n");
		return (0);
	}
	vars->size = ft_lstsize(vars->node_a);
	if (already_sort(vars->node_a))
	{
		all_free(vars->node_a, vars->node_b, vars->order);
		return (0);
	}
	if (vars->size <= 5)
		a_to_b_f(vars);
	else
		a_to_b(vars->size, vars);
	print_order(vars->order);
	all_free(vars->node_a, vars->node_b, vars->order);
}
