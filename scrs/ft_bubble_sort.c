
#include <stdio.h>
#include "ft_helper.c"

// Hauptfunktionen der vier Strategien
void ft_bubble_sort_stack(t_stack **a, t_stack **b, int size)
{
	int	count_array_loop1;
	int	count_array_loop2;
	int	swapped;

    if (*a == NULL || size <1)
        return ;

	(void)b;

	count_array_loop1 = -1;
	while (++count_array_loop1 < size - 1)
	{
		swapped = 0;
		count_array_loop2 = -1;
		while (++count_array_loop2 < size - 1)
		{
			if ((*a)->value > (*a)->next->value)
			{
				sa(a);
				swapped = 1;
			}
			ra(a);
		}
		ra(a);
		if (!swapped)
			break ;
	}
}

    // void	ft_sort_int_tab(int *tab, int size)

	// int	count_array_loop1;
	// int	count_array_loop2;
	// int	temp;

	// count_array_loop1 = 0;
	// while (count_array_loop1 < size - 1)
	// {
	// 	count_array_loop2 = 0;
	// 	while (count_array_loop2 < size - 1)
	// 	{
	// 		if (tab[count_array_loop2] > tab[count_array_loop2 + 1])
	// 		{
	// 			temp = tab[count_array_loop2];
	// 			tab[count_array_loop2] = tab[count_array_loop2 + 1];
	// 			tab[count_array_loop2 + 1] = temp;
	// 		}
	// 		count_array_loop2++;
	// 	}
	// 	count_array_loop1++;
	// }
