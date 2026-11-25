/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:36:27 by twalter           #+#    #+#             */
/*   Updated: 2026/11/24 14:37:37 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
