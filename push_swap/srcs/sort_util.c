/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:22:43 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 18:37:31 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sub_atoi(char *str, int *idx, int flag, int *result)
{
	int	i;

	i = *idx;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + str[i] - '0';
		i++;
	}
	*result *= flag;
	*idx = i;
	return (1);
}

static void	ft_atoi(char *str, t_list **node_a)
{
	int	i;
	int	result;

	i = 0;
	while (str[i] != '\0')
	{
		result = 0;
		if (!sub_atoi(str, &i, 1, &result))
			return ;
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
