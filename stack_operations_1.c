/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:20:39 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 16:07:32 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/// @brief (swap a): Swap the first two elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	sa(t_mode *mode)
{
	t_node *current_first;
	t_node *current_second;
	t_node *current_top;
	t_node *current_bottom;
	
	if (mode->size_a < 2)
		return (0);
	
	current_first = (t_node *)mode->head_a;
	current_top = current_first->top;
	current_second = current_first->bottom;
	current_bottom = current_second->bottom;

	current_first->top = current_second;
	current_first->bottom = current_bottom;

	current_second->top = current_top;
	current_second->bottom = current_first;

	current_top->bottom = current_second;
	current_bottom->top = current_first;

	current_first->position = 1;
	current_second->position = 0;

	mode->head_a = current_second;
	return (0);
}

/// @brief (swap b): Swap the first two elements at the top of stack b.
/// Do nothing if there is only one or no elements.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	sb(t_mode *mode)
{
	t_node *current_first;
	t_node *current_second;
	t_node *current_top;
	t_node *current_bottom;
	
	if (mode->size_b < 2)
		return (0);
	
	current_first = (t_node *)mode->head_b;
	current_top = current_first->top;
	current_second = current_first->bottom;
	current_bottom = current_second->bottom;

	current_first->top = current_second;
	current_first->bottom = current_bottom;

	current_second->top = current_top;
	current_second->bottom = current_first;

	current_top->bottom = current_second;
	current_bottom->top = current_first;

	current_first->position = 1;
	current_second->position = 0;

	mode->head_b = current_second;
	return (0);
}
/// @brief sa and sb at the same time
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	ss(t_mode *mode)
{
	sa(mode);
	sb(mode);

	return (0);
}
