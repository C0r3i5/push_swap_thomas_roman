#include "ft_bubble_sort.c"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		arr[] = {42, 10, 5, 99, 1};
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*new;
	int		i = 5;

	while (--i >= 0)
	{
		new = malloc(sizeof(t_stack));
		new->value = arr[i];
		new->next = a;
		a = new;
	}
	ft_bubble_sort_stack(&a, &b, 5);
	while (a && printf("%d ", a->value))
		a = a->next;
	printf("\n");
	return (0);
}