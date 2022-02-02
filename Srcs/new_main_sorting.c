#include "../include.h"

void       ft_main_sorting(t_node **stack_a, t_node **stack_b, int num)
{
    int     tmp[num];
    t_node  *ptr;
    int     i;

    i = 0;
    ptr = *stack_a;
    while (ptr->next != NULL)
    {
        tmp[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }
    
}