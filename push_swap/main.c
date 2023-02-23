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
#include <stdio.h>

void node_a_init(t_list **node_a, char **av)
{
    void *temp;

    for (long long i = 1; av[i] != NULL; i++)
    {
        temp = ((void *)atoi(av[i]));
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

void ft_sa(t_list **l, t_list **r)
{
    t_list *temp;
    t_list *left;
    t_list *right;

    left = *l;
    right = *r;
    temp = (t_list *)malloc(sizeof(t_list));
    if (temp == NULL)
        return;
    temp->content = left->content;
    temp->idx = left->idx;
    left->content = right->content;
    left->idx = right->idx;
    right->content = temp->content;
    right->idx = temp->idx;
    free(temp);
}

void ft_pb(t_list **l_node, t_list **left, int *pb, t_list **node_b)
{
    t_list *temp;

    temp = (*l_node);
    while (temp->idx < (*left)->idx)
    {
        ft_lstadd_front(node_b, temp);
        (*node_b)->next = NULL;
        temp = temp->next;
    }
    del_front(l_)
}

void quick_sort(t_list **l_node, t_list **r_node, t_list **node_b, t_list **order, long long ac)
{
    t_list *left = *l_node;
    t_list *right = *r_node; // ft_lstlast(*node_a);
    t_list *pivot = ft_lstmid(left, right);

    while (left->idx <= right->idx &&
           right->idx - left->idx <= 2)
    {
        while (left->content < pivot->content)
            left = left->next;
        while (right->content > pivot->content)
            right = right->prev;
        if (left->idx == 0 && right->idx == 1)
        {
            ft_sa(&left, &right);
            left = left->next;
            right = right->prev;
            break;
        }
    }
    int pb = 0;
    if ((*l_node)->idx < left->idx)
    {
        ft_pb(l_node, left, &pb, node_b);
    }
    quick_sort(&left, r_node, node_b, order, ac);
    // if ((*l_node)->idx < right->idx)
    // {
    //     ft_qsort(l_node, right);
    // }
    // if ((*r_node)->idx > left->idx)
    // {
    //     ft_qsort(left, r_node);
    // }
}

void ft_qsort(int *arr, int L, int R)
{
    int left = L, right = R, pivot = (left + right) / 2;

    while (left <= right)
    {
        while (arr[left] < arr[pivot])
            left++;
        while (arr[right] > arr[pivot])
            right--;
        if (left <= right)
        {
            ft_swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    if (L < right)
    {
        ft_qsort(arr, L, right);
    }
    if (R > left)
    {
        ft_qsort(arr, left, R);
    }
}

int main(long long ac, char **av)
{
    t_list *node_a;
    t_list *node_b;
    t_list *order;
    node_a = NULL; // node_init();
    node_b = NULL;

    node_a_init(&node_a, av);
    quick_sort(&node_a, &node_b, &order, ac);
    print_node_a(node_a);
}