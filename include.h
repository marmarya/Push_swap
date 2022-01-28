#ifndef INCLUDE_H
#define INCLUDE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Libft/libft.h"


typedef struct  s_node
{
    int             data;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

typedef struct  s_stack
{
    int             size;
    struct s_node   *top;
}           t_stack;


t_node      *new_node(int data);
void        print_stack(t_node *stack);
void        ft_push(t_node  **stack, int data);
void        ft_push_end(t_node **stack, int data);
int         ft_pop(t_node **stack);
int         ft_pop_end(t_node **stack);
int         ft_element_count(t_node *stack);
void        ft_push_to_a(t_node **stack_a, t_node **stack_b);
void        ft_push_to_b(t_node **stack_b, t_node **stack_a);
void        ft_swap_a(t_node **stack);
void        ft_swap_b(t_node **stack);
void        ft_sa_sb(t_node **stack_a, t_node **stack_b);
void        ft_rotate_a(t_node **stack);
void        ft_rotate_b(t_node **stack);
void        ft_ra_rb(t_node **stack_a, t_node **stack_b);
void        ft_reverse_rotate_a(t_node **stack);
void        ft_reverse_rotate_b(t_node **stack);
void        ft_rra_rrb(t_node **stack_a, t_node **stack_b);
void        ft_list_making(int argc, char **argv, t_node **stack_a);
void        ft_choose_sorting(t_node **stack_a, t_node **stack_b, int argc);
void        ft_sort3(t_node **stack_a);
void        ft_sort2(t_node **stack_a);
void        ft_sort4(t_node **stack_a, t_node **stack_b);
int         ft_find_min(t_node *stack_a);
void        ft_sort5(t_node **stack_a, t_node ** stack_b);
t_stack     *init_stack(void);
void        ft_init(t_stack *stack_a, int *num, int size);
void        ft_operations(t_stack *stack, int   i);


#endif //include.h 