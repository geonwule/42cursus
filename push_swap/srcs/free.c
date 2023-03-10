/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:24:46 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 18:27:43 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mal_free(t_list *node)
{
	t_list	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

void	all_free(t_list *node_a, t_list *node_b, t_list *order)
{
	mal_free(node_a);
	mal_free(node_b);
	mal_free(order);
}
