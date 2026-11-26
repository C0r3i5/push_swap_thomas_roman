/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 13:07:57 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Shift down all elements of a stack by one.
/// The last element becomes the first one.
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter
static void	rotate_r_stack(t_node **head, size_t *size)
{
	if (*size < 2)
		return ;
	*head = (*head)->top;
	heal_node_list(head, size);
}

/// @brief (reverse rotate a): Shift down all elements of stack a by one.
/// The last element becomes the first one.
/// @param mode Program configuration and operation counters
void	rra(t_mode *mode)
{
	if (mode->size_a < 2)
		return ;
	rotate_r_stack(&mode->head_a, &mode->size_a);
	mode->rra += 1;
	ft_printf("rra\n");
}

/// @brief (reverse rotate b): Shift down all elements of stack b by one.
/// The last element becomes the first one.
/// @param mode Program configuration and operation counters
void	rrb(t_mode *mode)
{
	if (mode->size_b < 2)
		return ;
	rotate_r_stack(&mode->head_b, &mode->size_b);
	mode->rrb += 1;
	ft_printf("rrb\n");
}

/// @brief rra and rrb at the same time
/// @param mode Program configuration and operation counters
void	rrr(t_mode *mode)
{
	if (mode->size_a < 2 && mode->size_b < 2)
		return ;
	rotate_r_stack(&mode->head_a, &mode->size_a);
	rotate_r_stack(&mode->head_b, &mode->size_b);
	mode->rrr += 1;
	ft_printf("rrr\n");
}
