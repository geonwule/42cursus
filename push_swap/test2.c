#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int ac, char **av)
{
    printf("%lld\n", (((long long)22 + (long long)INT_MAX) / 2));
}
/*void a_to_b(int size, t_list **node_a, t_list **node_b, t_list **order)
{
    // printf("---------a-------------size = %d\n",size);
    // printf("check = %d\n", ++check);
    // printf("-----------node_a-------\n");
    // print_node_a(*node_a);
    // printf("-----------node_b-------\n");
    // print_node_a(*node_b);
    if (size <= 1)
        return;
    long long pivot, ra_c = 0, pb_c = 0;
    long long x = (*node_a)->content;
    long long y = (*node_a)->next->content;
    pivot = ((x + y) / 2);
    // pivot = (((*node_a)->content + (*node_a)->next->content) / 2);
    if (pivot < 0 || (pivot == 0 && (x < 0 || y < 0)))
        pivot -= 1;
    //printf("-----pivot = %lld\n", pivot);
    for (int i = 0; i < size; i++)
    {
        if ((*node_a)->content > pivot)
        {
            ft_ra(node_a, order, 1);
            ra_c++;
        }
        else
        {
            if (ft_lstsize(*node_b) == 1 && (*node_b)->content == -1000)
            {
                fuck = 1;
            }
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
        return ;
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
}*/