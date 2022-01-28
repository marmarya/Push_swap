#include "../include.h"

int    ft_pop(t_node **stack)
{
    int ret;
    t_node *delete;
    if (!(delete = (t_node *)malloc(sizeof(t_node *))))
        return (0);
    if (stack == NULL)
        return (0);
    delete = *stack;
    ret = delete->data;
    *stack = (*stack)->next;
    free(delete);
    return(ret);
}

int     ft_pop_end(t_node **stack)
{
    int ret;
    t_node  *delete;
    t_node  *last;
    last = *stack;
    if (stack == NULL)
        return (0);
    while (last->next->next != NULL)
    {
        last = last->next;
    }
    delete = last->next;
    ret = delete->data;
    last->next = NULL;
    free(delete);
    return(ret);
}

void    ft_push_end(t_node **stack, int data)
{
    t_node *tmp;
	tmp = new_node(data);
    t_node *last;
    last = *stack;
	while (last->next != NULL)
	{
        // printf("push_end_check\n");
		last = last->next;
	}
	last->next = tmp;
}

void    ft_push(t_node  **stack, int data)
{
    // printf("push\n");
    t_node *tmp;
    tmp = new_node(data);
    tmp->next = *stack;
    *stack = tmp;
}

t_node  *new_node(int data)
{
    t_node  *new;
    new = malloc(sizeof(t_node *));
    if (!new)
        return (0);
    new->data = data;
    new->next = NULL;
    return (new);
}