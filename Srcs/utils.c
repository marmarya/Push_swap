#include "../include.h"

int     ft_element_count(t_node *stack)
{
    int count;
    t_node *stack_count;
    stack_count = stack;
    while (stack_count->next != NULL)
    {
        stack_count = stack_count->next;
        count++;
    }
    return (count);
}

void    print_stack(t_node *stack)
{
    t_node *tmp;
    tmp = stack;
    if (tmp == NULL)
    {
        printf("Stack is empty\n");
        return ;
    }
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);  
        tmp = tmp->next;
    }
}

// void    ft_list_making(int argc, char **argv, t_node **stack_a)
// {
//     int i;
//     int j;
//     int data;
//     // t_node *push;

//     i = 1;
//     // printf("argv---%s", *argv);
//     while (*argv[i] != '\0')
//     {
//         // printf("check\n");
//         data = ft_atoi(argv[i]);
//         ft_push_end(stack_a, data);
//         i++;
//     }
//     // printf("stack_a\n");
//     print_stack(*stack_a);
// }