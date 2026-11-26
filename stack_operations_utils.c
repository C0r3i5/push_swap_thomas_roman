/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:36:27 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 13:08:30 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Rotate stack a to bring the node at pos to the top via shortest path
/// @param mode Program configuration and operation counters
/// @param pos Zero-based target index in stack a
void	rotate_to_pos(t_mode *mode, size_t pos)
{
	size_t	steps;

	if (pos <= mode->size_a / 2)
	{
		while (pos-- > 0)
			ra(mode);
		return ;
	}
	steps = mode->size_a - pos;
	while (steps-- > 0)
		rra(mode);
}

/// @brief Find the insertion index in stack a for val
/// @param mode Program configuration and operation counters
/// @param val Value to insert from stack b
/// @return Zero-based target index in stack a
size_t	find_insert_pos(t_mode *mode, int val)
{
	t_node	*cur;
	size_t	idx;
	size_t	pos;

	pos = 0;
	cur = mode->head_a;
	idx = 0;
	while (idx < mode->size_a && mode->size_a >= 2)
	{
		if (cur->value < val && val < cur->bottom->value)
		{
			pos = (idx + 1) % mode->size_a;
			break ;
		}
		cur = cur->bottom;
		idx++;
	}
	return (pos);
}

void	calculate_rank(t_mode *mode)
{
	t_node	*cur;
	t_node	*cmp;
	size_t	idx_out;
	size_t	idx_in;

	idx_out = 0;
	cur = mode->head_a;
	while (idx_out < mode->size_a)
	{
		idx_in = 0;
		cur->helper = 0;
		cmp = mode->head_a;
		while (idx_in < mode->size_a)
		{
			if (cur->value > cmp->value)
				cur->helper++;
			cmp = cmp->bottom;
			idx_in++;
		}
		cur = cur->bottom;
		idx_out++;
	}
}

size_t	find_max_pos_b(t_mode *mode)
{
	t_node	*cur;
	size_t	idx;
	size_t	max_pos;
	int		max_value;

	cur = mode->head_b;
	max_value = cur->value;
	max_pos = 0;
	idx = 0;
	while (idx < mode->size_b)
	{
		if (cur->value > max_value)
		{
			max_value = cur->value;
			max_pos = idx;
		}
		cur = cur->bottom;
		idx++;
	}
	return (max_pos);
}

void	rotate_b_to_pos(t_mode *mode, size_t pos)
{
	size_t	steps;

	if (mode->size_b == 0 || pos >= mode->size_b)
		return ;
	if (pos <= mode->size_b / 2)
	{
		while (pos > 0)
		{
			rb(mode);
			pos--;
		}
		return ;
	}
	steps = mode->size_b - pos;
	while (steps > 0)
	{
		rrb(mode);
		steps--;
	}
}
