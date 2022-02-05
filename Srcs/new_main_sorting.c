#include "../include.h"

void    ft_merge_sort(int   num, int    tmp[num], int   begin, int mid, int end)
{
    int i, j, k;
    int array1_size = mid - begin + 1;
    int array2_size = end - mid;
}

void    ft_merge(int num, int    tmp[num], int   begin, int end)
{
    int     mid;

    if (begin < end)
    {

        mid = (begin + end) / 2;
        ft_merge(num, tmp, begin, mid);
        ft_merge(num, tmp, mid + 1, end);
        ft_merge_sort(num, tmp, begin, mid, end);
    }
}

void       ft_main_sorting(t_node **stack_a, t_node **stack_b, int num)
{
    int     tmp[num];
    t_node  *ptr;
    int     i;
    int     begin;
    int     end;

    i = 0;
    ptr = *stack_a;
    while (ptr->next != NULL)
    {
        tmp[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }
    begin = tmp[0];
    end = tmp[i];
    ft_merge(num, tmp, begin, end);
}