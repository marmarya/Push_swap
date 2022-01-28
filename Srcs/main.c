#include "../include.h"

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     *num;

    num = malloc(4 * (argc - 1));
    if (!num)
        return (0);
    stack_a = init_stack();
	stack_b = init_stack();
    ft_helper(argc, stack_a, stack_b, num);
    free(num);
}

void    ft_helper(int   argc, t_stack *stack_a, t_stack *stack_b, int num)
{
    ft_init(stack_a, num, argc - 1);
    if (argc <= 6)
    {
        ft_choose_sorting(stack_a, stack_b, argc - 1);
        return ;
    }
    ft_push_to_b(stack_b, stack_a);
    ft_main(stack_a, stack_b);
}