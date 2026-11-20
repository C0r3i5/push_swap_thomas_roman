/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 16:07:42 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/// @brief (rotate a): Shift up all elements of stack a by one.
/// The first element becomes the last one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	ra(t_mode *mode)
{
	t_node	*current_head;

	if (mode->size_a < 2)
		return (0);

	current_head = (t_node *)mode->head_a;
	mode->head_a = current_head->bottom;
}

/// @brief (rotate b): Shift up all elements of stack b by one.
/// The first element becomes the last one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rb(t_mode *mode)
{
	t_node	*current_head;

	if (mode->size_b < 2)
		return (0);

	current_head = (t_node *)mode->head_b;
	mode->head_b = current_head->bottom;
}

/// @brief ra and rb at the same time.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rr(t_mode *mode)
{
	ra(mode);
	rb(mode);
}