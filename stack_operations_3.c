/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 19:13:42 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	rotate_r_stack(t_node **head, size_t *size)
{
	t_node	*current_head;

	if (*size < 2)
		return ;

	current_head = *head;
	*head = current_head->top;
	heal_node_list(head, size);
}

/// @brief (reverse rotate a): Shift down all elements of stack a by one.
/// The last element becomes the first one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rra(t_mode *mode)
{
	rotate_r_stack(&mode->head_a, &mode->size_a);
}

/// @brief (reverse rotate b): Shift down all elements of stack b by one.
/// The last element becomes the first one.
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rrb(t_mode *mode)
{
	rotate_r_stack(&mode->head_b, &mode->size_b);
}

/// @brief rra and rrb at the same time
/// @param mode The list with the config/mode values (pointer to head)
/// @return success 0, fail -1
int	rrr(t_mode *mode)
{
	rra(mode);
	rrb(mode);
}