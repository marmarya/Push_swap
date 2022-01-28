#include "../include.h"

int     ft_checks(char **argv, int n)
{
    int i;
    int j;

    i = 1;
    while (i < n)
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == '-' && ((argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')))
            {
                ++j;
                continue ;
            }
            else if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (1);
            ++j;
        }
        // if (!ft_atoi(argv[i] >= -2147483648 && ft_atoi(argv[i] <= 2147483647)))
        //     return (1);
        ++i;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     i;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    if (ft_checks(argv, argc))
    {
        write(1, "Error\n", 6);
        return (0);
    }
    i = argc;
    while (i > 1)
    {
        ft_push(&stack_a, ft_atoi(argv[i - 1]));
        --i;
    }
    if (check_dubs(stack_a))
    {
        write(1, "Error\n", 6);
        return (0);
    }
    if (!stack_check(stack_a))
        ft_choose_sorting(&stack_a, &stack_b, argc);
    print_stack(stack_a);
    return (0);
}

