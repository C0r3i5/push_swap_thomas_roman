/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:23 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 09:10:28 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// loeschen
void print_stack(t_node *stack)
{
	while (stack != NULL)
	{
		printf("value: %d '\t' address: %p '\t rank: %d\n",
			stack->value,
			(void *)stack,
			stack->helper);
		stack = stack->bottom;
	}
}
///////////////




static int ft_chunk_count(size_t size)
{
	int chunk_count;
	int chunk_size;

	chunk_count = 1;
	while (chunk_count * chunk_count < size)
		chunk_count++;

	chunk_size = (size + chunk_count - 1) / chunk_count;

	return (chunk_size);
}

static void normalize_stack(t_node *stack, size_t max_chunc)
{
	t_node *current;
	t_node *other;
	int     rank;

	current = stack;
	while (current != NULL)
	{
		rank = 0;
		other = stack;
		while (other != NULL)
		{
			if (other->value < current->value)
				rank++;
			other = other->bottom;
		}
		current->helper = rank / max_chunc;
		current = current->bottom;
	}
}






void	sort_medium(t_mode *mode)
{
	int d;
	int i;


	d = ft_chunk_count(mode->size_a);

	normalize_stack((mode->head_a, d);

	print_stack(mode->head_a);
	d--;
	while (d >= 0)
	{
		i = 0;
		while (i < mode->size_a)
		{
			if (mode->head_a->helper == d && mode->head_a->bottom != NULL)
				pb(mode);
			ra(mode);
			i++;
		}
		while (mode->head_b != NULL)
		{
			rotate_to_pos(mode, find_insert_pos(mode,(*b)->value));
			pa(mode);
		}
		d--;
	}

	print_stack(mode->head_a);

	(void)mode->head_b;

}





// int ft_find_max(t_mode *stack)
// {
// 	int max_val;

// 	if (stack == NULL)
// 		return (0);

// 	max_val = stack->head_a;
// 	while (stack != NULL)
// 	{
// 		if (stack->value > max_val)
// 			max_val = stack->value;
// 		stack = stack->next;
// 	}
// 	return (max_val);
// }

// int ft_find_min(t_stack *stack)
// {
// 	int min_val;

// 	if (stack == NULL)
// 		return (0);

// 	min_val = stack->value;
// 	while (stack != NULL)
// 	{
// 		if (stack->value < min_val)
// 			min_val = stack->value;
// 		stack = stack->next;
// 	}
// 	return (min_val);
// }



#include <stdio.h>






// size_t	find_insert_pos(t_stack *stack, int val, size_t size)
// {
// 	t_stack	*cur;
// 	t_stack	*next;
// 	size_t	idx;
// 	size_t	min_pos;

// 	if (size < 2 || stack == NULL || stack->next == NULL)
// 		return (0);
// 	cur = stack;
// 	idx = 0;
// 	min_pos = 0;
// 	while (idx < size && cur != NULL)
// 	{
// 		next = cur->next;
// 		if (next == NULL)
// 			next = stack;
// 		if (cur->value < val && val < next->value)
// 			return ((idx + 1) % size);
// 		if (cur->value > next->value)
// 			min_pos = (idx + 1) % size;
// 		cur = cur->next;
// 		idx++;
// 	}
// 	return (min_pos);
// }



// void	rotate_to_pos(t_stack **a, size_t pos, size_t size)
// {
// 	size_t	steps;

// 	if (pos <= size / 2)
// 	{
// 		while (pos-- > 0)
// 			ra(a);
// 		return ;
// 	}
// 	steps = size - pos;
// 	while (steps-- > 0)
// 		rra(a);
// }




// #include <stddef.h> // Für size_t




// void	ft_chunk_sort(t_stack **a, t_stack **b, int size)
// {

// }
