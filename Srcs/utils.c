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

int     getelem(t_node  *node, int n)
{
    t_node *ptr;
    ptr = node;
    int count;
    count = 0;
    while (ptr != NULL)
    {
        if(count == n)
            return (ptr)->data;
        count++;
        ptr = ptr->next;
    }
    return (0);
}

int     stack_size(t_node *node)
{
    int     i;
    t_node  *ptr;

    ptr = node;
    i = 0;
    if (ptr == NULL)
        return (0);
    else
    {
        while (ptr != NULL)
        {
            i++;
            ptr = ptr->next;
        }
        return (i);
    }
}