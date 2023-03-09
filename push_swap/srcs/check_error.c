/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:13:18 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/09 20:03:01 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(t_list *node)
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

static int	over_int(char *str)
{
	long long	i;
	long long	flag;
	long long	result;

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
		result = 0;
		if (str[i] == '\0')
			break ;
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

static int	no_integer(char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			flag = 1;
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				flag = -1;
				j++;
			}
			if ((flag == -1 && av[i][j] == '\0') ||
				!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1); // error not integer
			while (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
		}
		i++;
	}
	return (0);
}

static int	min_digit_check(int ac, char **av)
{
	int	i;
	int	j;
	int	cnt;

	i = 1;
	while (i < ac)
	{
		j = 0;
		cnt = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				cnt++;
			j++;
		}
		if (cnt == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_error(t_list **node, int ac, char **av)
{
	int	i;

	if (ac < 2 || min_digit_check(ac, av) || no_integer(av))
		return (1);
	i = 1;
	while (av[i] != NULL)
	{
		if (over_int(av[i]))
			return (1); // error overflow || underflow int
		i++;
	}
	node_a_init(node, av);
	if (is_duplicate(*node))
	{
		if (*node)
			mal_free(*node);
		return (1);
	}
	return (0);
}