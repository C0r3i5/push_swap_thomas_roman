/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:23:14 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 14:02:50 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

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
	return (node);
}

/// @brief Check if the new value is already in the list
/// @param lst The existing list
/// @param value The new value to check
/// @return Dublicate 1, unique 0
int	find_dub(t_node **lst, int value) 
{
	t_node *node_current;
	t_node *node_start;
	
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

/// @brief Append new node to a existing list if value is unique
/// @param lst_a The existing list with values
/// @param node The new node canidate
/// @return Error -1, Success 0
int	append_unique(t_node **lst_a, t_node *node, t_mode *mode)
{
	t_node *node_current_last;
	t_node *node_start;

	if (*lst_a == NULL)
	{
		mode->head_a = node;
		node->bottom = node;
		node->top = node;
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

	mode->size_a += 1;
	return (0);
}

/// @brief Calculate a number between 0 and 1 that tells how far your initial
/// stack a is from being sorted.
/// @param lst List A with the current values
/// @param mode The list for setting the mode 
/// @return If the numbers are already in the right order, the disorder is 0. 
/// If they are in the worst possible order, the disorder is 1.
double	compute_disorder(t_node *lst, t_mode mode)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node *node_current_1;
	t_node *node_current_2;
	size_t	idx;
	
	mistakes = 0;
	total_pairs = 0;
	idx = 0;
	node_current_1 = mode.head_a;
	while (node_current_1->bottom != mode.head_a || total_pairs == 0)
	{
		node_current_2 = node_current_1;
		while (node_current_2->bottom != mode.head_a || idx == 0)
		{
			total_pairs += 1;
			if (node_current_1->value > node_current_2->bottom->value)
				mistakes++;
			node_current_2 = node_current_2->bottom;
			idx++;
		}
		idx = 0;
		node_current_1 = node_current_1->bottom;
	}
	return((double)mistakes / total_pairs);
}