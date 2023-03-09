/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:22:43 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/09 17:58:48 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_atoi(char *str, t_list **node_a)
{
	int	i;
	int	flag;
	int	result;

	i = 0;
	while (str[i] != '\0')
	{
		while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
			i++;
		flag = 1;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				flag *= -1;
			i++;
		}
		if (str[i] == '\0')
			return ;
		result = 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		result *= flag;
		ft_lstadd_back(node_a, ft_lstnew("", result));
	}
}

void	node_a_init(t_list **node_a, char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		ft_atoi(av[i], node_a);
		i++;
	}
}

void	print_order(t_list *order)
{
	while (order)
	{
		ft_printf("%s\n", (char *)order->order);
		order = order->next;
	}
}