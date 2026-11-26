/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:23:14 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 13:20:21 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Create a new unconnected node with the value
/// @param value Signed Int value
/// @return The new node or NULL
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node) * 1);
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->bottom = node;
	node->top = node;
	node->position = 0;
	return (node);
}

/// @brief Check if the new value is already in the list
/// @param lst The existing list
/// @param value The new value to check
/// @return Duplicate 1, unique 0
int	find_dub(t_node **lst, int value)
{
	t_node	*node_current;
	t_node	*node_start;

	if (lst == NULL)
		return (0);
	node_start = *lst;
	if (node_start == NULL)
		return (0);
	if (node_start->value == value)
		return (1);
	node_current = node_start->bottom;
	while (node_current != node_start)
	{
		if (value == node_current->value)
			return (1);
		node_current = node_current->bottom;
	}
	return (0);
}

/// @brief Append new node to an existing list if value is unique
/// @param lst_a The existing list with values
/// @param node The new node candidate
/// @param mode Program configuration and operation counters
/// @return Error -1, Success 0
int	append_unique(t_node **lst_a, t_node *node, t_mode *mode)
{
	t_node	*node_current_last;
	t_node	*node_start;

	if (*lst_a == NULL)
	{
		mode->head_a = node;
		node->bottom = node;
		node->top = node;
		node->position = 0;
		*lst_a = node;
		mode->size_a = 1;
		return (0);
	}
	node_start = (t_node *)mode->head_a;
	if (find_dub(lst_a, node->value) == 1)
		return (-1);
	node_current_last = node_start->top;
	node_current_last->bottom = node;
	node_start->top = node;
	node->top = node_current_last;
	node->bottom = node_start;
	node->position = mode->size_a;
	mode->size_a += 1;
	return (0);
}

/// @brief Calculate a number between 0 and 1 that tells how far your initial
/// stack a is from being sorted.
/// @param mode Program configuration and operation counters
/// @return If the numbers are already in the right order, the disorder is 0. 
/// If they are in the worst possible order, the disorder is 1.
double	compute_disorder(t_mode mode)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node	*node_current_1;
	t_node	*node_current_2;

	if (mode.head_a == NULL || mode.size_a < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = mode.size_a * (mode.size_a - 1) / 2;
	node_current_1 = mode.head_a;
	while (node_current_1->bottom != mode.head_a)
	{
		node_current_2 = node_current_1->bottom;
		while (node_current_2 != mode.head_a)
		{
			if (node_current_1->value > node_current_2->value)
				mistakes++;
			node_current_2 = node_current_2->bottom;
		}
		node_current_1 = node_current_1->bottom;
	}
	return ((double)mistakes / total_pairs);
}

/// @brief Recalculate node positions and update the stack size
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter to update
void	heal_node_list(t_node **head, size_t *size)
{
	t_node	*node_current;
	t_node	*node_head;
	size_t	idx;

	idx = 0;
	if (*head == NULL)
		return ;
	node_head = *head;
	node_head->position = idx;
	idx++;
	node_current = node_head->bottom;
	while (node_current != node_head)
	{
		node_current->position = idx;
		node_current = node_current->bottom;
		idx++;
	}
	*size = idx;
}
