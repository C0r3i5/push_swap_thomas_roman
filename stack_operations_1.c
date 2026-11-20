/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:20:39 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 19:28:00 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	swap(t_node **head, size_t *size)
{
	t_node	*first_node;
	t_node	*second_node;

	if (*size < 2)
		return ;

	first_node = *head;
	second_node = first_node->bottom;

	if (*size > 2)
	{
		first_node->top->bottom = second_node;
		second_node->bottom->top = first_node;
		second_node->top = first_node->top;
		first_node->bottom = second_node->bottom;
		first_node->top = second_node;
		second_node->bottom = first_node;
	}
	second_node->position = 0;
	first_node->position = 1;
	*head = second_node;
}

/// @brief (swap a): Swap the first two elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	sa(t_mode *mode)
{
	swap(&mode->head_a, &mode->size_a);
	return (0);
}



/// @brief (swap b): Swap the first two elements at the top of stack b.
/// Do nothing if there is only one or no elements.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	sb(t_mode *mode)
{
	swap(&mode->head_b, &mode->size_b);
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
