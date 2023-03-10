/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:10:07 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 18:40:31 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_list *node)
{
	t_list		*t_node;
	t_list		*head;
	long long	temp;
	long long	temp_cnt;

	head = node;
	while (node)
	{
		temp = node->content;
		temp_cnt = 0;
		t_node = head;
		while (t_node)
		{
			if (temp == t_node->content)
			{
				temp_cnt++;
				if (temp_cnt == 2)
					return (1);
			}
			t_node = t_node->next;
		}
		node = node->next;
	}
	return (0);
}

static int	sub_over_int(char *str, long long i, long long flag,
						long long result)
{
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
		result = 0;
		if (str[i] == '\0')
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		result *= flag;
		if (result > (long long)INT_MAX || result < (long long)INT_MIN)
			return (1);
	}
	return (0);
}

int	over_int(char *str)
{
	if (sub_over_int(str, 0, 1, 0))
		return (1);
	return (0);
}
