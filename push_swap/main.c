#include <unistd.h>
#include <stdlib.h>

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

// temporary stdio printf
#include <stdio.h>

// sort_utils
void node_a_init(t_list **node_a, char **av);
void print_node_a(t_list *node_a);
t_list *ft_lstmid(t_list *left, t_list *right);
void print_order(t_list *order);
void mal_free(t_list *node);

// void quick_sort(t_list **l_node, t_list **r_node, t_list **node_b, t_list **order, long long ac)
// {
//     t_list *left = *l_node;
//     t_list *right = *r_node; // ft_lstlast(*node_a);
//     t_list *pivot = ft_lstmid(left, right);

//     while (left->idx <= right->idx &&
//            right->idx - left->idx <= 2)
//     {
//         while (left->content < pivot->content)
//             left = left->next;
//         while (right->content > pivot->content)
//             right = right->prev;
//         if (left->idx == 0 && right->idx == 1)
//         {
//             ft_sa(&left, &right);
//             left = left->next;
//             right = right->prev;
//             break;
//         }
//     }
//     int pb = 0;
//     if ((*l_node)->idx < left->idx)
//     {
//         ft_pb(l_node, left, &pb, node_b);
//     }
//     quick_sort(&left, r_node, node_b, order, ac);
//     // if ((*l_node)->idx < right->idx)
//     // {
//     //     ft_qsort(l_node, right);
//     // }
//     // if ((*r_node)->idx > left->idx)
//     // {
//     //     ft_qsort(left, r_node);
//     // }
// }

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

void    my_sort(t_list *node)
{
    long long pivot;
    long long node_size = ft_lstsize(node);

    int i = 0;
    while (i < node_size)
    {
        if ((long long)node->content >= pivot)
            ft_ra(node, order, 0);
        else
            ft_pb(node, node_b, order);
        i++;
    }

    
    if (node_b)
        b_to_a();
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

    node_a_init(&node_a, av);
    node_a_last = ft_lstlast(node_a);
    my_sort(&node_a, &node_b, &order);
    // quick_sort(&node_a, &node_a_last, &node_b, &order, ac);
    print_node_a(node_a);
    print_order(order);
    mal_free(node_a);
    mal_free(node_b);
    mal_free(order);
}

// sort_ utils

void node_a_init(t_list **node_a, char **av)
{
    void *temp;

    for (long long i = 1; av[i] != NULL; i++)
    {
        temp = ((void *)atoi(av[i]));   // modify a_to_llong
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
        ft_printf("%s\n", order->content);
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
    (*node_b)->prev = NULL;
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