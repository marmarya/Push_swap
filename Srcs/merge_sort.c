#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int		ft_is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' ||
		c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	// printf("atoi\n");
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (result * sign);
		i++;
	}
	return (result * sign);
}

void    ft_merge_sort(int    tmp[], int   begin, int mid, int end)
{
    int i, j, k;
    int array1_size = mid - begin + 1;
    int array2_size = end - mid;
    int array1[array1_size];
    int array2[array2_size];
    
    i = 0;
    j = 0;
    k = begin;
    while (i < array1_size)
    {
        array1[i] = tmp[begin + i];
        i++;
    }
    while (j < array2_size)
    {
        array2[j] = tmp[mid + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    while (i < array1_size && j < array2_size)
    {
        if (array1[i] <= array2[j])
        {
            tmp[k] = array1[i];
            i++;
        }
        else
        {
            tmp[k] = array1[i];
            i++;
        }
        k++;
    }
    while (i < array1_size)
    {
        tmp[k] = array1[i];
        i++;
        k++;
    }
    while (j < array2_size)
    {
        tmp[k] = array2[j];
        j++;
        k++;
    }
}

void    ft_print_array(int    array[], int   num)
{
    // printf("print");
    int i = 0;
    while (i < num)
    {
        printf("%d\n", array[i]);
        i++;
    }
}

void    ft_merge(int    tmp[], int   begin, int end)
{
    int     mid;

    if (begin < end)
    {

        mid = (begin + end) / 2;
        ft_merge(tmp, begin, mid);
        ft_merge(tmp, mid + 1, end);
        ft_merge_sort(tmp, begin, mid, end);
    }
    // ft_print_array(tmp, end);
    // printf("chheck\n");
}


int     main(int    argc, char **argv)
{
    int i = 0;
    int     *array;
    // printf("Cehck\n");

  //  array = malloc(sizeof(int) * (argc - 1));
    //if (!array)
      //  return (0);
    int begin, end;
    while (i < argc - 1)
    {
        array[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    int a[] = { 11, 30, 24, 7, 31, 16, 39, 41 };  
    begin = 0;
    end = argc - 2;
    ft_merge(a, 0, 7);
    ft_print_array(a, 7);
}