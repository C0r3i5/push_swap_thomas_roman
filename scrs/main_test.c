#include "ft_insertion_sort_stack.c"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		arr[] = {2, 8, 3, 42, 43, 10, 5, 99, 1};
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*new;
	int		i = 9;

	while (--i >= 0)
	{
		new = malloc(sizeof(t_stack));
		new->value = arr[i];
		new->next = a;
		a = new;
	}
	// ft_bubble_sort_stack(&a, &b, 5);
	insertion_sort_stack(&a, &b, 9);
	while (a && printf("%d ", a->value))
		a = a->next;
	printf("\n");
	return (0);
}
