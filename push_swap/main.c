#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

// linked list
typedef struct s_list
{
    void *order;
    long long content;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *ft_lstnew(void *order, long long content);
static t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *node);

// error_check
static int is_duplicate(t_list *node);
static int over_int(char *str);
static int no_integer(char **av);
int min_digit_check(char **av);
int error_check(t_list **node, int ac, char **av);

// order
int ft_sa(t_list *node, t_list **order, int flag);
int ft_sb(t_list *node, t_list **order, int flag);
void ft_ss(t_list *node_a, t_list *node_b, t_list **order);
void ft_pa(t_list **node_a, t_list **node_b, t_list **order);
void ft_pb(t_list **node_a, t_list **node_b, t_list **order);
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
void a_to_b(int size, t_list **node_a, t_list **node_b, t_list **order);
void b_to_a(int size, t_list **node_a, t_list **node_b, t_list **order);

// int check = 0; // remove
// #include <stdio.h>
// int fuck = 0;

void a_to_b(int size, t_list **node_a, t_list **node_b, t_list **order)
{
    if (size <= 1)
        return;
    long long pivot, ra_c = 0, pb_c = 0;
    long long x = (*node_a)->content;
    long long y = (*node_a)->next->content;
    pivot = ((x + y) / 2);
    if (pivot < 0 || (pivot == 0 && (x < 0 || y < 0)))
        pivot -= 1;
    for (int i = 0; i < size; i++)
    {
        if ((*node_a)->content > pivot)
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

void b_to_a(int size, t_list **node_a, t_list **node_b, t_list **order)
{
    if (size <= 0)
        return;
    if (size == 1)
    {
        ft_pa(node_a, node_b, order);
        return;
    }
    long long pivot, rb_c = 0, pa_c = 0;
    long long x = (*node_b)->content;
    long long y = (*node_b)->next->content;
    pivot = ((x + y) / 2);
    if (pivot < 0 || (pivot == 0 && (x < 0 || y < 0)))
        pivot -= 1;
    pivot = (((*node_b)->content + (*node_b)->next->content) / 2);
    if (pivot <= 0)
        pivot -= 1;
    for (int i = 0; i < size; i++)
    {
        if ((*node_b)->content <= pivot)
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
    a_to_b(pa_c, node_a, node_b, order);
    b_to_a(rb_c, node_a, node_b, order);
}

char **temp_av(void)
{
    char **av = (char **)malloc(sizeof(char *) * 4);
    for (int i = 0; i < 3; i++)
    {
        av[i] = (char *)malloc(sizeof(char) * 10);
    }
    av[0] = "a.out";
    av[1] = "-2";
    av[2] = "-3";
    av[3] = NULL;
    // av[4] = "0";
    // av[5] = "4";
    // av[6] = NULL;
    // av[3] = "-2147483648";
    // av[4] = "6";
    // av[5] = "5";
    // av[6] = "8";
    // av[7] = NULL;
    return (av);
}

int already_sort(t_list *node_a)
{
    int i;
    long long temp;

    // 1 2 3 4 5
    i = 0;
    node_a = node_a->next;
    while (node_a)
    {
        temp = node_a->prev->content;
        if (temp > node_a->content)
            return (0);
        node_a = node_a->next;
    }
    mal_free(node_a);
    return (1);
}

int main(int ac, char **av)
{
    t_list *node_a;
    t_list *node_b;
    t_list *order;
    int size;
    // char **av = temp_av();
    // int ac = 3;
    node_a = NULL; // node_init();
    node_b = NULL;
    order = NULL;
    if (error_check(&node_a, ac, av))
    {
        printf("Error\n");
        return (0);
    }
    size = ft_lstsize(node_a);
    if (already_sort(node_a))
        return (0);
    a_to_b(size, &node_a, &node_b, &order);
    print_node_a(node_a);
    // print_order(order);
    mal_free(node_a);
    mal_free(node_b);
    mal_free(order);
}

// error_check
static int is_duplicate(t_list *node)
{
    t_list *t_node;
    t_list *head;
    int temp;
    int temp_cnt;

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

static int over_int(char *str)
{
    long long i;
    long long flag;
    long long result;

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
            break;
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

static int no_integer(char **av)
{
    int i;
    int j;
    int flag;

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
            if (flag == -1 && av[i][j] == '\0' ||
                !(av[i][j] >= '0' && av[i][j] <= '9'))
                return (1); // error not integer
            while (av[i][j] >= '0' && av[i][j] <= '9')
                j++;
        }
        i++;
    }
    return (0);
}

int min_digit_check(char **av)
{
    int i;
    int j;
    int cnt;

    i = 1;
    while (av[i] != NULL)
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

int error_check(t_list **node, int ac, char **av)
{
    if (ac < 2 || min_digit_check(av) || no_integer(av))
        return (1);
    for (int i = 1; av[i] != NULL; i++)
    {
        if (over_int(av[i]))
            return (1); // error overflow || underflow int
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

// sort_ utils
static void ft_atoi(char *str, t_list **node_a)
{
    int i;
    int flag;
    int result;

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
        if (str[i] == '\0')
            return;
        result = 0;
        while (str[i] && str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + str[i] - '0';
            i++;
        }
        result *= flag;
        ft_lstadd_back(node_a, ft_lstnew("", result));
    }
}

void node_a_init(t_list **node_a, char **av)
{
    for (int i = 1; av[i] != NULL; i++)
    {
        ft_atoi(av[i], node_a);
    }
}

void print_node_a(t_list *node_a)
{
    while (node_a)
    {
        printf("%d\n", (int)node_a->content);
        node_a = node_a->next;
    }
}

/*
t_list *ft_lstmid(t_list *left, t_list *right)
{
    int mid_idx;
    t_list *mid;

    mid_idx = (left->content + right->content) / 2;
    while (left->content < mid_idx)
        left = left->next;
    mid = left;
    return (mid);
}*/

void print_order(t_list *order)
{
    while (order)
    {
        printf("%s\n", (char *)order->order); // ft_printf
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

t_list *ft_lstnew(void *order, long long content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->order = order;
    new->content = content;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

int ft_lstsize(t_list *node)
{
    int size;

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
    int temp;

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
    int temp;

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

void ft_pa(t_list **node_a, t_list **node_b, t_list **order)
{
    t_list *temp;

    ft_lstadd_back(order, ft_lstnew("pa", 0));
    if ((*node_b) == NULL)
        return;
    temp = *node_b;
    (*node_b) = (*node_b)->next;
    temp->next = NULL;
    if (*node_b)
        (*node_b)->prev = NULL; // SEGV
    ft_lstadd_front(node_a, temp);
}

void ft_pb(t_list **node_a, t_list **node_b, t_list **order)
{
    t_list *temp;

    ft_lstadd_back(order, ft_lstnew("pb", 0));
    if ((*node_a) == NULL)
        return;
    temp = *node_a;
    (*node_a) = (*node_a)->next;
    temp->next = NULL;
    if (*node_a)
        (*node_a)->prev = NULL; // SEGV
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