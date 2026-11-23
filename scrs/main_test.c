#include "ft_bubble_sort.c"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Vertauscht die obersten beiden Elemente von Stack A.
 *
 * Hat keine Auswirkung, wenn der Stack leer ist oder nur ein Element enthält.
 * Gibt bei erfolgreicher Ausführung "sa\n" auf der Standardausgabe aus.
 *
 * @param a Doppelzeiger auf den Anfang (Top) von Stack A.
 */
void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	printf("sa\n");
}

/**
 * @brief Rotiert alle Elemente von Stack A um eine Position nach oben.
 *
 * Das oberste Element (Top) wird an das untere Ende (Bottom) des Stapels
 * verschoben, während das zweite Element zur neuen Spitze wird. Hat keine
 * Auswirkung bei weniger als zwei Elementen. Gibt "ra\n" aus.
 *
 * @param a Doppelzeiger auf den Anfang (Top) von Stack A.
 */
void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	printf("ra\n");
}

/**
 * @brief Verschiebt das oberste Element von Stack A an die Spitze von Stack B.
 *
 * Hat keine Auswirkung, wenn Stack A leer ist. Gibt bei erfolgreicher
 * Ausführung "pb\n" auf der Standardausgabe aus.
 *
 * @param a Doppelzeiger auf den Anfang (Top) von Stack A.
 * @param b Doppelzeiger auf den Anfang (Top) von Stack B.
 */
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	printf("pb\n");
}

/**
 * @brief Verschiebt das oberste Element von Stack B an die Spitze von Stack A.
 *
 * Hat keine Auswirkung, wenn Stack B leer ist. Gibt bei erfolgreicher
 * Ausführung "pa\n" auf der Standardausgabe aus.
 *
 * @param a Doppelzeiger auf den Anfang (Top) von Stack A.
 * @param b Doppelzeiger auf den Anfang (Top) von Stack B.
 */
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	printf("pa\n");
}

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