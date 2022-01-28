#include "../include.h"

void    ft_merge(int    arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    i = 0;
    j = 0;
    while(i < n1)
    {
        L[i] = arr[l + i];
        i++;
    }
    while (j < n2)
    {
        R[j] = arr[m + 1 + j];
        j++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void    merge_sort(int  arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        ft_merge(arr, l, m, r);
    }
}

void    main_sorting(t_node **stack_a, t_node **stack_b, int n)
{
    int     tmp_arr[n];
    t_node  *ptr;
    int     i;
    int     point;
    int     len;
    int     index;

    i = 0;
    len = 0;
    ptr = *stack_a;
    index = 0;
    while (ptr != NULL)
    {
        tmp_arr[i] = ptr->data;
        ptr = ptr->next;
        ++i;
    }
    merge_sort(tmp_arr, 0, n -1);
    point = tmp_arr[n / 3];
    i = 0;
    while (i < n)
    {
        if ((*stack_a)->data > point && getelem(*stack_a, stack_size(*stack_a) - 1) < point)
            ft_reverse_rotate_a(stack_a);
        else if ((*stack_a)->data < point)
        {
            ft_push_to_b(stack_b, stack_a);
            if (stack_size(*stack_b) >= 2)
            {
                if ((*stack_b)->data < (*stack_b)->next->data)
                    ft_swap_b(stack_b);
            }
            ++len;
        }
        else if (stack_size(*stack_b) > 1 && (*stack_b)->data < (*stack_b)->next->data)
            ft_ra_rb(stack_a, stack_b);
        else
            ft_rotate_a(stack_a);
        ++i;
    }
    if (stack_size(*stack_a) == 3)
        ft_sort3(stack_a);
    if (stack_size(*stack_a) > 3)
        main_sorting(stack_a, stack_b, (n - len));
    while (stack_size(*stack_b))
    {
        i = 0;
        point = (*stack_b)->data;
        while (++i < stack_size(*stack_b))
        {
            if (getelem(*stack_b, i) > point)
            {
                point = getelem(*stack_b, i);
                index = i;
            }
        }
        if (index <= stack_size(*stack_b) / 2)
        {
            index++;
            while (--index)
                ft_rotate_b(stack_b);
        }
        else
        {
            while (index++ < stack_size(*stack_b))
                ft_reverse_rotate_b(stack_b);
        }
        ft_push_to_a(stack_a, stack_b); //kara sxal lini argumenty
    }
}