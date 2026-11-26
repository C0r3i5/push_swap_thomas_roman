/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:12:12 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 13:08:16 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Cut the top node from the list
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter
/// @return The removed top node, or NULL if the list is empty
static t_node	*cut_headnode(t_node **head, size_t *size)
{
	t_node	*first_node;
	t_node	*top_node;
	t_node	*second_node;

	if (*head == NULL || *size == 0)
		return (NULL);
	first_node = *head;
	if (*size == 1)
		*head = NULL;
	else
	{
		top_node = first_node->top;
		second_node = first_node->bottom;
		second_node->top = top_node;
		top_node->bottom = second_node;
		*head = second_node;
	}
	first_node->top = first_node;
	first_node->bottom = first_node;
	*size -= 1;
	return (first_node);
}

/// @brief Add a node to the top of the list
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter to update
/// @param new_node The new node
static void	add_headnode(t_node **head, size_t *size, t_node *new_node)
{
	t_node	*first_node;
	t_node	*top_node;

	if (new_node == NULL)
		return ;
	if (*size == 0)
	{
		new_node->top = new_node;
		new_node->bottom = new_node;
	}
	else
	{
		first_node = *head;
		top_node = first_node->top;
		top_node->bottom = new_node;
		first_node->top = new_node;
		new_node->top = top_node;
		new_node->bottom = first_node;
	}
	*head = new_node;
	*size += 1;
}

/// @brief (push a): Take the first element at the top of b and put 
/// it at the top of a. Do nothing if b is empty.
/// @param mode Program configuration and operation counters
void	pa(t_mode *mode)
{
	t_node	*node;

	node = cut_headnode(&mode->head_b, &mode->size_b);
	if (node == NULL)
		return ;
	add_headnode(&mode->head_a, &mode->size_a, node);
	heal_node_list(&mode->head_a, &mode->size_a);
	heal_node_list(&mode->head_b, &mode->size_b);
	mode->pa += 1;
	ft_printf("pa\n");
}

/// @brief (push b): Take the first element at the top of a and put 
/// it at the top of b. Do nothing if a is empty.
/// @param mode Program configuration and operation counters
void	pb(t_mode *mode)
{
	t_node	*node;

	node = cut_headnode(&mode->head_a, &mode->size_a);
	if (node == NULL)
		return ;
	add_headnode(&mode->head_b, &mode->size_b, node);
	heal_node_list(&mode->head_a, &mode->size_a);
	heal_node_list(&mode->head_b, &mode->size_b);
	mode->pb += 1;
	ft_printf("pb\n");
}
