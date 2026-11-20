/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:23:14 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 13:30:12 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
	node->next = node;
	node->prev = node;
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
	node_current = node_start->next;
	while (node_current != node_start)
	{
		if (value == node_current->value)
			return (1);
		node_current = node_current->next;
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
		node->next = node;
		node->prev = node;
		*lst_a = node;
		mode->size_a = 1;
		return (0);
	}
	node_start = (t_node *)mode->head_a;
	if (find_dub(lst_a, node->value) == 1)
		return (-1);
	
	node_current_last = node_start->prev;
	node_current_last->next = node;
	node_start->prev = node;
	node->prev = node_current_last;
	node->next = node_start;

	mode->size_a += 1;
	return (0);
}