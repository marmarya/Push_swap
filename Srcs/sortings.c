#include "../include.h"

void    ft_choose_sorting(t_node **stack_a, t_node **stack_b, int argc)
{
    if (argc == 2) // 1 tiv
        return ;
    if (argc == 3) // 2 tiv
        ft_sort2(stack_a);
    if (argc == 4) // 3 tiv
        ft_sort3(stack_a);
    if (argc == 5)
        ft_sort4(stack_a, stack_b);
    if (argc == 6)
        ft_sort5(stack_a, stack_b);
}

void    ft_sort2(t_node **stack_a)
{
    int     tmp;
    if ((*stack_a)->next->data < (*stack_a)->data)
        ft_swap_a(stack_a);
}

void    ft_sort3(t_node **stack_a)
{
    // 1 3 2
    // print_stack(*stack_a);
    if (((*stack_a)->data < (*stack_a)->next->data) && ((*stack_a)->next->data > (*stack_a)->next->next->data) && ((*stack_a)->data < (*stack_a)->next->next->data))
    {
        ft_swap_a(stack_a);
        ft_rotate_a(stack_a);
    }
    // 2 1 3
    else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->next->data < (*stack_a)->next->next->data) && ((*stack_a)->data < (*stack_a)->next->next->data))
            ft_swap_a(stack_a);
    // 2 3 1
    else if (((*stack_a)->data < (*stack_a)->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data))
            ft_reverse_rotate_a(stack_a);
    // 3 2 1
    else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->next->data > (*stack_a)->next->next->data))
    {
        ft_swap_a(stack_a);
        ft_reverse_rotate_a(stack_a);
    }
    // 3 1 2
    else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->next->data < (*stack_a)->next->next->data)
            && ((*stack_a)->data > (*stack_a)->next->next->data))
        ft_rotate_a(stack_a);
    else
        return ;
}

void    ft_sort4(t_node **stack_a, t_node **stack_b)
{
    int     min;

    min = ft_find_min(*stack_a);
    while ((*stack_a)->data != min)
    {
        ft_rotate_a(stack_a);
    }
    ft_push_to_b(stack_b, stack_a);
    ft_sort3(stack_a);
    ft_push_to_a(stack_a, stack_b);
}

void    ft_sort5(t_node **stack_a, t_node **stack_b)
{
    int min;
    min = ft_find_min(*stack_a);
    while ((*stack_a)->data != min)
    {
        ft_rotate_a(stack_a);
    }
    ft_push_to_b(stack_b, stack_a);
    ft_sort4(stack_a, stack_b);
    ft_push_to_a(stack_a, stack_b);
}

int     ft_find_min(t_node *stack_a)
{
    int     min;
    t_node *tmp;
    tmp = stack_a;
    min = (tmp)->data;
    while (tmp != NULL)
    {
        if ((tmp)->data < min)
            min = (tmp)->data;
        tmp = (tmp)->next;
    }
    return (min);
}
