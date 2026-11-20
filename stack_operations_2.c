/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 19:10:32 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	rotate_stack(t_node **head, size_t *size)
{
	t_node	*current_head;

	if (*size < 2)
		return ;

	current_head = *head;
	*head = current_head->bottom;
	heal_node_list(head, size);
}

/// @brief (rotate a): Shift up all elements of stack a by one.
/// The first element becomes the last one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	ra(t_mode *mode)
{
	rotate_stack(&mode->head_a, &mode->size_a);
}

/// @brief (rotate b): Shift up all elements of stack b by one.
/// The first element becomes the last one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rb(t_mode *mode)
{
	rotate_stack(&mode->head_b, &mode->size_b);
}

/// @brief ra and rb at the same time.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rr(t_mode *mode)
{
	ra(mode);
	rb(mode);
}