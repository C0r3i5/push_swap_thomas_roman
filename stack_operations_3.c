/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:49:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 20:15:01 by twalter          ###   ########.fr       */
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
/// @param mode The list with the config/mode values (pointer to head)
void	rrb(t_mode *mode)
{
	if (mode->size_b < 2)
		return ;
	rotate_r_stack(&mode->head_b, &mode->size_b);
	mode->rrb += 1;
	ft_printf("rrb\n");
}

/// @brief rra and rrb at the same time
/// @param mode The list with the config/mode values (pointer to head)
void	rrr(t_mode *mode)
{
	if (mode->size_a < 2 && mode->size_b < 2)
		return ;
	rotate_r_stack(&mode->head_a, &mode->size_a);
	rotate_r_stack(&mode->head_b, &mode->size_b);
	mode->rrr += 1;
	ft_printf("rrr\n");
}