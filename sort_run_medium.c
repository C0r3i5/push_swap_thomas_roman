/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:23 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 14:54:41 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the optimal chunk size based on the total element count.
 *
 * Splits the total size into a fixed number of chunks (5 chunks for up to
 * 100 elements, otherwise 11 chunks) and returns the rounded-up size of a
 * single chunk.
 *
 * @param size The total number of elements to process.
 * @return int The calculated number of elements per chunk.
 */
static int	ft_chunk_count(size_t size)
{
	int	chunk_count;
	int	chunk_size;

	if (size <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	chunk_size = (size + chunk_count - 1) / chunk_count;
	return (chunk_size);
}

/**
 * @brief Assigns a chunk index to each node based on its relative value rank.
 *
 * Iterates through the stack to determine each element's sorted rank by
 * counting smaller values, then divides the rank by max_chunc and stores the
 * resulting chunk group in node->helper.
 *
 * @param stack Pointer to the top node of the stack.
 * @param size Total number of elements in the stack.
 * @param max_chunc Size of a single chunk used to group ranks.
 */
static void	normalize_stack(t_node *stack, int size, size_t max_chunc)
{
	t_node	*current;
	t_node	*other;
	int		rank;
	int		j;

	if (!stack || size <= 0 || max_chunc == 0)
		return ;
	current = stack;
	while (size-- > 0)
	{
		rank = 0;
		other = stack;
		j = -1;
		while (other && ++j < size + 1)
		{
			if (other->value < current->value)
				rank++;
			other = other->bottom;
		}
		current->helper = rank / max_chunc;
		current = current->bottom;
	}
}

/**
 * @brief Pushes elements from stack A to stack B in descending chunk order.
 *
 * Iterates through stack A for each chunk index from d down to 0. Elements
 * matching the current chunk index are pushed to stack B (pb), while others
 * are rotated to the bottom of stack A (ra).
 *
 * @param mode Pointer to the main program structure holding both stacks.
 * @param d The highest chunk index to start pushing from.
 */
static void	push_chunks_to_b(t_mode *mode, int d)
{
	int	i;
	int	cur_size;

	while (d >= 0)
	{
		i = 0;
		cur_size = mode->size_a;
		while (i < cur_size)
		{
			if (mode->head_a != NULL && mode->head_a->helper == d)
				pb(mode);
			else
				ra(mode);
			i++;
		}
		d--;
	}
}

void	sort_medium(t_mode *mode)
{
	int	chunk;
	int	size;
	int	d;

	size = mode->size_a;
	if (size <= 1)
		return ;
	chunk = ft_chunk_count(size);
	normalize_stack(mode->head_a, size, chunk);
	d = ((size + chunk - 1) / chunk) - 1;
	print_stack(mode);
	push_chunks_to_b(mode, d);
	print_stack(mode);
	while (mode->head_b != NULL)
	{
		rotate_b_to_pos(mode, find_max_pos_b(mode));
		pa(mode);
		print_stack(mode);
	}
}

