#include "../include.h"

int     check_dubs(t_node *stack_a)
{
    while (stack_a->next != NULL)
    {
        t_node *ptr = stack_a->next;
        while (ptr != NULL)
        {
            if (stack_a->data == ptr->data)
                return 1;
            ptr = ptr->next;
        }
        stack_a = stack_a->next;
    }
    return (0);
}

int     stack_check(t_node *node)
{
    t_node *ptr;
    ptr = node;
    while (ptr->next != NULL)
    {
        if (ptr->data > ptr->next->data)
            return (0);
        ptr = ptr->next;
    }
    return (1);
}