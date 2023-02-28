#include <unistd.h>
#include <stdlib.h>

// linked list
typedef struct s_list
{
    void *content;
    long long idx;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *ft_lstnew(void *content, long long idx);
static t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
long long ft_lstsize(t_list *node);

// order
int ft_sa(t_list *node, t_list **order, int flag);
int ft_sb(t_list *node, t_list **order, int flag);
void ft_ss(t_list *node_a, t_list *node_b, t_list **order);
int ft_pa(t_list **node_a, t_list **node_b, t_list **order);
int ft_pb(t_list **node_a, t_list **node_b, t_list **order);
void ft_ra(t_list **node, t_list **order, int flag);
void ft_rb(t_list **node, t_list **order, int flag);
void ft_rr(t_list **node_a, t_list **node_b, t_list **order);
void ft_rra(t_list **node, t_list **order, int flag);
void ft_rrb(t_list **node, t_list **order, int flag);
void ft_rrr(t_list **node_a, t_list **node_b, t_list **order);

// temporary stdio printf
#include <stdio.h>

// sort_utils
void node_a_init(t_list **node_a, char **av);
void print_node_a(t_list *node_a);
t_list *ft_lstmid(t_list *left, t_list *right);
void print_order(t_list *order);
void mal_free(t_list *node);
void a_to_b(long long size, t_list **node_a, t_list **node_b, t_list **order);
void b_to_a(long long size, t_list **node_a, t_list **node_b, t_list **order);

void a_to_b(long long size, t_list **node_a, t_list **node_b, t_list **order)
{
    if (size == 1)
        return;
    long long pivot, ra_c = 0, pb_c = 0;
    // t_list *last = ft_lstlast(*node_a);
    pivot = (((long long)(*node_a)->content + (long long)(*node_a)->next->content) / 2);

    for (int i = 0; i < size; i++)
    {
        if ((long long)(*node_a)->content > pivot)
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

void b_to_a(long long size, t_list **node_a, t_list **node_b, t_list **order)
{
    if (size == 1)
    {
        ft_pa(node_a, node_b, order);
        return;
    }
    long long pivot, rb_c = 0, pa_c = 0;
    // t_list *last = ft_lstlast(*node_b);
    pivot = (((long long)(*node_b)->content + (long long)(*node_b)->next->content) / 2);

    for (int i = 0; i < size; i++)
    {
        if ((long long)(*node_b)->content <= pivot)
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
    a_to_b(rb_c, node_a, node_b, order);
    b_to_a(pa_c, node_a, node_b, order);
}

char **temp_av(void)
{
    char **av = (char **)malloc(sizeof(char *) * 8);
    for (int i = 0; i < 7; i++)
    {
        av[i] = (char *)malloc(sizeof(char) * 10);
    }
    av[0] = "a.out";
    av[1] = "2";
    av[2] = "1";
    av[3] = "3";
    av[4] = "6";
    av[5] = "5";
    av[6] = "8";
    av[7] = NULL;
    return (av);
}

void free_av(char **av)
{
    for (int i = 0; av[i] != NULL; i++)
        free(av[i]);
    free(av);
}

int main(long long ac, char **av)
{
    t_list *node_a;
    t_list *node_a_last;
    t_list *node_b;
    t_list *order;
    node_a = NULL; // node_init();
    node_b = NULL;
    order = NULL;
    // char **av = temp_av();
    if (ac <= 1)
    {
        printf("Error not enough argument\n");
        return (0); // error
    }
    node_a_init(&node_a, av);
    node_a_last = ft_lstlast(node_a);
    long long size = ft_lstsize(node_a);
    a_to_b(size, &node_a, &node_b, &order);
    // my_sort(&node_a, &node_b, &order);
    //  quick_sort(&node_a, &node_a_last, &node_b, &order, ac);
    print_node_a(node_a);
    //print_order(order);
    mal_free(node_a);
    mal_free(node_b);
    mal_free(order);
}

// sort_ utils
static long long   ft_atoll(char *str)
{
	long long	i;
	long long	flag;
	long long	result;

	i = 0;
	result = 0;
	flag = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result *= flag;
	return (result);

}
void node_a_init(t_list **node_a, char **av)
{
    void *temp;

    for (long long i = 1; av[i] != NULL; i++)
    {
        temp = ((void *)ft_atoll(av[i])); // modify a_to_llong
        ft_lstadd_back(node_a, ft_lstnew(temp, i));
    }
}

void print_node_a(t_list *node_a)
{
    while (node_a)
    {
        printf("%lld\n", (long long)node_a->content);
        node_a = node_a->next;
    }
}

t_list *ft_lstmid(t_list *left, t_list *right)
{
    long long mid_idx;
    t_list *mid;

    mid_idx = (left->idx + right->idx) / 2;
    while (left->idx < mid_idx)
        left = left->next;
    mid = left;
    return (mid);
}

void print_order(t_list *order)
{
    while (order)
    {
        printf("%s\n", (char *)order->content); // ft_printf
        order = order->next;
    }
}

void mal_free(t_list *node)
{
    t_list *temp;

    while (node)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// linked list

t_list *ft_lstnew(void *content, long long idx)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->content = content;
    new->idx = idx;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

long long ft_lstsize(t_list *node)
{
    long long size;

    size = 0;
    while (node)
    {
        size++;
        node = node->next;
    }
    return (size);
}

static t_list *ft_lstlast(t_list *lst)
{
    t_list *last;

    if (lst == NULL)
        return (0);
    while (lst)
    {
        last = lst;
        lst = lst->next;
    }
    return (last);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (new == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    temp = *lst;
    new->prev = ft_lstlast(temp);
    ft_lstlast(temp)->next = new;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *temp = *lst;

    if (new == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        (*lst)->prev = NULL;
        return;
    }
    temp->prev = new;
    new->next = temp;
    *lst = new;
}

// order

int ft_sa(t_list *node, t_list **order, int flag)
{
    void *temp;

    if (node == NULL || node->next == NULL)
        return (0);
    temp = node->content;
    node->content = node->next->content;
    node->next->content = temp;
    if (flag)
        ft_lstadd_back(order, ft_lstnew("sa", 0));
    return (1);
}

int ft_sb(t_list *node, t_list **order, int flag)
{
    void *temp;

    if (node == NULL || node->next == NULL)
        return (0);
    temp = node->content;
    node->content = node->next->content;
    node->next->content = temp;
    if (flag)
        ft_lstadd_back(order, ft_lstnew("sb", 0));
    return (1);
}

void ft_ss(t_list *node_a, t_list *node_b, t_list **order)
{
    int a;
    int b;

    a = ft_sa(node_a, order, 0);
    b = ft_sb(node_b, order, 0);
    if (a && b)
        ft_lstadd_back(order, ft_lstnew("ss", 0));
}

int ft_pa(t_list **node_a, t_list **node_b, t_list **order)
{
    t_list *temp;

    ft_lstadd_back(order, ft_lstnew("pa", 0));
    if ((*node_b) == NULL)
        return (0);
    temp = *node_b;
    (*node_b) = (*node_b)->next;
    temp->next = NULL;
    if (*node_b)
        (*node_b)->prev = NULL; // SEGV
    ft_lstadd_front(node_a, temp);
}

int ft_pb(t_list **node_a, t_list **node_b, t_list **order)
{
    t_list *temp;

    ft_lstadd_back(order, ft_lstnew("pb", 0));
    if ((*node_a) == NULL)
        return (0);
    temp = *node_a;
    (*node_a) = (*node_a)->next;
    temp->next = NULL;
    (*node_a)->prev = NULL;
    ft_lstadd_front(node_b, temp);
}

void ft_ra(t_list **node, t_list **order, int flag)
{
    t_list *temp;

    if (flag)
        ft_lstadd_back(order, ft_lstnew("ra", 0));
    if ((*node) == NULL || (*node)->next == NULL)
        return;
    temp = *node;
    *node = (*node)->next;
    temp->next = NULL;
    (*node)->prev = NULL;
    ft_lstadd_back(node, temp);
}

void ft_rb(t_list **node, t_list **order, int flag)
{
    t_list *temp;

    if (flag)
        ft_lstadd_back(order, ft_lstnew("rb", 0));
    if ((*node) == NULL || (*node)->next == NULL)
        return;
    temp = *node;
    *node = (*node)->next;
    temp->next = NULL;
    (*node)->prev = NULL;
    ft_lstadd_back(node, temp);
}

void ft_rr(t_list **node_a, t_list **node_b, t_list **order)
{
    ft_ra(node_a, order, 0);
    ft_rb(node_b, order, 0);
    ft_lstadd_back(order, ft_lstnew("rr", 0));
}

void ft_rra(t_list **node, t_list **order, int flag)
{
    t_list *temp;
    t_list *last;

    if (flag)
        ft_lstadd_back(order, ft_lstnew("rra", 0));
    if ((*node) == NULL || (*node)->next == NULL)
        return;
    last = ft_lstlast(*node)->prev;
    temp = last->next;
    last->next = NULL;
    temp->prev = NULL;
    ft_lstadd_front(node, temp);
    *node = temp;
}

void ft_rrb(t_list **node, t_list **order, int flag)
{
    t_list *temp;
    t_list *last;

    if (flag)
        ft_lstadd_back(order, ft_lstnew("rrb", 0));
    if ((*node) == NULL || (*node)->next == NULL)
        return;
    last = ft_lstlast(*node)->prev;
    temp = last->next;
    last->next = NULL;
    temp->prev = NULL;
    ft_lstadd_front(node, temp);
    *node = temp;
}

void ft_rrr(t_list **node_a, t_list **node_b, t_list **order)
{
    ft_rra(node_a, order, 0);
    ft_rrb(node_b, order, 0);
    ft_lstadd_back(order, ft_lstnew("rrr", 0));
}