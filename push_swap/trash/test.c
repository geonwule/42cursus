#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    long long idx;
    struct s_list *next;
    struct s_list *prev;
} t_list;

// t_list *node_init(void)
// {
//     t_list *new;

//     new = (t_list *)malloc(sizeof(t_list));
//     if (new == NULL)
//         return (0);
//     new->arg = 0;
//     new->head = 0;
//     new->next = NULL;
//     return (new);
// }

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

#include <stdio.h>

void print_node(t_list *s)
{
    while (s)
    {
        printf("%s\n", (char *)s->content);
        s = s->next;
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

// int main()
// {
//     t_list *head = ft_lstnew((void *)123999, 123);

//     printf("%lld\n", (long long)head->content);
//}
int main()
{
    t_list *a = NULL;
    t_list *b = NULL;
    t_list *order = NULL;

    ft_lstadd_back(&a, ft_lstnew("1", 0));
    ft_lstadd_back(&a, ft_lstnew("2", 0));
    ft_lstadd_back(&a, ft_lstnew("3", 0));
    ft_lstadd_back(&a, ft_lstnew("4", 0));
    ft_lstadd_back(&a, ft_lstnew("5", 0));
    ft_lstadd_back(&a, ft_lstnew("6", 0));
    ft_lstadd_back(&a, ft_lstnew("7", 0));
    ft_lstadd_back(&a, ft_lstnew("8", 0));
    ft_pb(&a, &b, &order);
    ft_pb(&a, &b, &order);
    ft_pb(&a, &b, &order);
    ft_pb(&a, &b, &order);
    ft_ss(a, b, &order);
    ft_pa(&a, &b, &order);
    ft_pa(&a, &b, &order);
    ft_pa(&a, &b, &order);
    // ft_pb(&a, &b, &order);
    // ft_ss(a, b, &order);
    // ft_rrr(&a, &b, &order);
    // ft_rra(&a, &order, 1);
    // ft_rrb(&b, &order, 1);
    printf("----a-----\n");
    print_node(a);
    printf("----b-----\n");
    print_node(b);
    printf("----order-----\n");
    print_node(order);
    printf("\n");
    mal_free(a);
    mal_free(b);
    mal_free(order);
}