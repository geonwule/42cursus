/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:13:18 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/10 17:33:58 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sub_no_int(char **av, int i, int j, int flag)
{
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
			return (1);
		else if (av[i][j] == '\0')
			return (0);
		while (av[i][j] >= '0' && av[i][j] <= '9')
			j++;
	}
}

static int	no_integer(char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (av[++i] != NULL)
	{
		j = 0;
		if (sub_no_int(av, i, j, flag))
			return (1);
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
			return (1);
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
