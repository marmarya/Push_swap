#include "../include.h"

void    ft_rotate_a(t_node **stack)
{
    int     data;
    data = ft_pop(stack);
    ft_push_end(stack, data);
    write (1, "ra\n", 3);
}

void    ft_rotate_b(t_node **stack)
{
    int data;
    data = ft_pop(stack);
    ft_push_end(stack, data);
    write (1, "rb\n", 3);
}

void    ft_ra_rb(t_node **stack_a, t_node **stack_b)
{
    int data;
    data = ft_pop(stack_a);
    ft_push_end(stack_a, data);
    data = ft_pop(stack_b);
    ft_push_end(stack_b, data);
    write (1, "rr\n", 3);
}

void    ft_reverse_rotate_a(t_node **stack)
{
    int data;
    data = ft_pop_end(stack);
    ft_push(stack, data);
    write (1, "rra\n", 4);
}

void    ft_reverse_rotate_b(t_node **stack)
{
    int data;
    data = ft_pop_end(stack);
    ft_push(stack, data);
    write (1, "rrb\n", 4);
}

void    ft_rra_rrb(t_node **stack_a, t_node **stack_b)
{
    int data;
    data = ft_pop_end(stack_a);
    ft_push(stack_a, data);
    data = ft_pop_end(stack_b);
    ft_push(stack_b, data);
    write (1, "rrr\n", 4);
}