/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:03:56 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/09 20:01:59 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// linked list
typedef struct s_list
{
	void			*order;
	long long		content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*ft_lstnew(void *order, long long content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *node);

// ft_printf
int					ft_printf(const char *str, ...);

// check_error
int					check_error(t_list **node, int ac, char **av);

// util_a_to_b
int					already_sort(t_list *node_a);
void				b_to_a_f(int size, t_list **node_a, t_list **node_b,
						t_list **order);
void				a_to_b_f(int size, t_list **node_a, t_list **node_b,
						t_list **order);

// order1
int					ft_sa(t_list *node, t_list **order, int flag);
int					ft_sb(t_list *node, t_list **order, int flag);
void				ft_ss(t_list *node_a, t_list *node_b, t_list **order);
void				ft_pa(t_list **node_a, t_list **node_b, t_list **order);
void				ft_pb(t_list **node_a, t_list **node_b, t_list **order);
// order2
void				ft_ra(t_list **node, t_list **order, int flag);
void				ft_rb(t_list **node, t_list **order, int flag);
void				ft_rr(t_list **node_a, t_list **node_b, t_list **order);
// order3
void				ft_rra(t_list **node, t_list **order, int flag);
void				ft_rrb(t_list **node, t_list **order, int flag);
void				ft_rrr(t_list **node_a, t_list **node_b, t_list **order);

// sort_utils
void				node_a_init(t_list **node_a, char **av);
void				print_order(t_list *order);

// free
void				mal_free(t_list *node);
void				all_free(t_list *node_a, t_list *node_b, t_list *order);
// temporary void				print_node_a(t_list *node_a);

// main
void				a_to_b(int size, t_list **node_a, t_list **node_b,
						t_list **order);
void				b_to_a(int size, t_list **node_a, t_list **node_b,
						t_list **order);

#endif