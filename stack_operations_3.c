/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 16:07:51 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/// @brief (reverse rotate a): Shift down all elements of stack a by one.
/// The last element becomes the first one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rra(t_mode *mode)
{
	t_node	*current_head;

	if (mode->size_a < 2)
		return (0);

	current_head = (t_node *)mode->head_a;
	mode->head_a = current_head->top;
}

/// @brief (reverse rotate b): Shift down all elements of stack b by one.
/// The last element becomes the first one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rrb(t_mode *mode)
{
	t_node	*current_head;

	if (mode->size_b < 2)
		return (0);

	current_head = (t_node *)mode->head_b;
	mode->head_b = current_head->top;
}

/// @brief rra and rrb at the same time
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rrr(t_mode *mode)
{
	rra(mode);
	rrb(mode);
}