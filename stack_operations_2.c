/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 13:07:32 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Shift up all elements of a stack by one.
/// The first element becomes the last one.
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter
static void	rotate_stack(t_node **head, size_t *size)
{
	if (*size < 2)
		return ;
	*head = (*head)->bottom;
	heal_node_list(head, size);
}

/// @brief (rotate a): Shift up all elements of stack a by one.
/// The first element becomes the last one.
/// @param mode Program configuration and operation counters
void	ra(t_mode *mode)
{
	if (mode->size_a < 2)
		return ;
	rotate_stack(&mode->head_a, &mode->size_a);
	mode->ra += 1;
	ft_printf("ra\n");
}

/// @brief (rotate b): Shift up all elements of stack b by one.
/// The first element becomes the last one.
/// @param mode Program configuration and operation counters
void	rb(t_mode *mode)
{
	if (mode->size_b < 2)
		return ;
	rotate_stack(&mode->head_b, &mode->size_b);
	mode->rb += 1;
	ft_printf("rb\n");
}

/// @brief ra and rb at the same time.
/// @param mode Program configuration and operation counters
void	rr(t_mode *mode)
{
	if (mode->size_a < 2 && mode->size_b < 2)
		return ;
	rotate_stack(&mode->head_a, &mode->size_a);
	rotate_stack(&mode->head_b, &mode->size_b);
	mode->rr += 1;
	ft_printf("rr\n");
}
