/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:12:12 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 18:47:01 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

int	pa(t_mode *mode)
{
	t_node	*node;

	node = cut_headnode(&mode->head_b, &mode->size_b);
	if (node == NULL)
		return (0);
	add_headnode(&mode->head_a, &mode->size_a, node);
		return (0);
}

int	pb(t_mode *mode)
{
	t_node	*node;

	node = cut_headnode(&mode->head_a, &mode->size_a);
	if (node == NULL)
		return (0);
	add_headnode(&mode->head_b, &mode->size_b, node);
		return (0);
}

void	heal_node_list(t_mode *mode)
{
	t_node *node_current;
	t_node *node_head;
	size_t	idx;

	idx = 0;
	if (node_head == NULL)
		return ;
	node_head = mode->head_a;

	node_head->position = idx;
	idx++;

	node_current = node_head->bottom;
	while (node_current != node_head)
	{
		node_current->position = idx;
		node_current = node_current->bottom;
		idx++;
	}
	mode->size_a = idx;
}