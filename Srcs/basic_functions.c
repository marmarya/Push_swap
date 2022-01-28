#include "../include.h"

void    ft_push_to_a(t_node **stack_a, t_node **stack_b)
{
    int data;
    // if (stack_b == NULL || ft_element_count(stack_b) == 1)
    //     return ;
    data = ft_pop(stack_b);
    ft_push(stack_a, data);
    write(1, "pa\n", 3);
}

void    ft_push_to_b(t_node **stack_b, t_node **stack_a)
{
    int data;
    // if (stack_a == NULL || ft_element_count(stack_a) == 1)
    //     return ;
    data = ft_pop(stack_a);
    ft_push(stack_b, data);
    write (1, "pb\n", 3);
}

void    ft_swap_a(t_node **stack)
{
    int tmp1;
    int tmp2;

    tmp1 = ft_pop(stack);
    tmp2= ft_pop(stack);
    ft_push(stack, tmp1);
    ft_push(stack, tmp2);
    write (1, "sa\n", 3);
}

void    ft_swap_b(t_node **stack)
{
    int tmp1;
    int tmp2;

    tmp1 = ft_pop(stack);
    tmp2= ft_pop(stack);
    ft_push(stack, tmp1);
    ft_push(stack, tmp2);
    write (1, "sb\n", 3);
}

void    ft_sa_sb(t_node **stack_a, t_node **stack_b)
{
    int tmp1;
    int tmp2;

    tmp1 = ft_pop(stack_a);
    tmp2= ft_pop(stack_a);
    ft_push(stack_a, tmp1);
    ft_push(stack_a, tmp2);
    tmp1 = ft_pop(stack_b);
    tmp2= ft_pop(stack_b);
    ft_push(stack_b, tmp1);
    ft_push(stack_b, tmp2);
    write (1, "ss\n", 3);
}