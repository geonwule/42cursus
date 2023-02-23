#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    void    *content;
    struct s_list *next;
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

t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->content = content;
    new->next = NULL;
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
        return;
    }
    new->next = temp;
    *lst = new;
}
#include <stdio.h>

void node_a_init(t_list **node_a, char **av)
{
    void *temp;
    int a = 99;

    for (int i = 1; av[i] != NULL; i++)
    {
        temp = ((void *)atoi(av[i]));
        //temp = (void *)a;
        ft_lstadd_back(node_a, ft_lstnew(temp));
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

void    quick_sort(t_list **node_a, t_list **node_b, t_list **order)
{
    if ()
        sa;
    if ()
        sb;
    if ()
        pa;
    if ()
        pb
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

int main(int ac, char **av)
{
    t_list *node_a;
    t_list *node_b;
    t_list *order;
    node_a = NULL; // node_init();
    node_b = NULL;

    node_a_init(&node_a, av);
    //quick_sort(&node_a, &node_b, &order);
    print_node_a(node_a);
}