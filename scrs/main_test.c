#include "ft_chunk_sort.c"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		arr[] = {2, 8, 3, 42, 43, 10, 5, 99, 1, 9542, 30, 70, 500, 22, 9994, -5};
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*new;
	int		i = 16;

	while (--i >= 0)
	{
		new = malloc(sizeof(t_stack));
		new->value = arr[i];
		new->next = a;
		a = new;
	}
	// ft_bubble_sort_stack(&a, &b, 5);
	ft_chunk_sort(&a, &b, 15);
	while (a && printf("%d ", a->value))
		a = a->next;
	printf("\n");
	return (0);
}
