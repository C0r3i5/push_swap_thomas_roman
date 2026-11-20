/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:12:12 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 18:30:07 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_node *cut_headnode_a(t_mode *mode)
{
	t_node *current_top;
	t_node *current_first;
	t_node *current_second;
	
	if (mode->head_a == NULL || mode->size_a == 0)
		return (NULL);
	current_first = (t_node *)mode->head_a;
	if (mode->size_a == 1)
		mode->head_a = NULL;
	else
	{
		current_top = current_first->top;
		current_second = current_first->bottom;
		current_second->top = current_top;
		current_top->bottom = current_second;
		mode->head_a = current_second;
	}
	current_first->top = current_first;
	current_first->bottom = current_first;
	mode->size_a -= 1;
	return (current_first);
}

t_node *cut_headnode_b(t_mode *mode)
{
	t_node *current_top;
	t_node *current_first;
	t_node *current_second;
	
	if (mode->head_b == NULL || mode->size_b == 0)
		return (NULL);
	current_first = (t_node *)mode->head_b;
	if (mode->size_b == 1)
		mode->head_b = NULL;
	else
	{
		current_top = current_first->top;
		current_second = current_first->bottom;
		current_second->top = current_top;
		current_top->bottom = current_second;
		mode->head_b = current_second;
	}
	current_first->top = current_first;
	current_first->bottom = current_first;
	mode->size_b -= 1;
	return (current_first);
}

void	add_headnode_a(t_mode *mode, t_node *new_node)
{
	t_node *current_top;
	t_node *current_first;

	if (new_node == NULL)
		return ;
	if (mode->size_a == 0)
	{
		new_node->top = new_node;
		new_node->bottom = new_node;
	}
	else
	{
		current_first = (t_node *)mode->head_a;
		current_top = current_first->top;
		current_top->bottom = new_node;
		current_first->top = new_node;
		new_node->top = current_top;
		new_node->bottom = current_first;
	}

	mode->head_a = new_node;
	mode->size_a += 1;
}

void	add_headnode_b(t_mode *mode, t_node *new_node)
{
	t_node *current_top;
	t_node *current_first;
	
	if (new_node == NULL)
		return ;
	if (mode->size_b == 0)
	{
		new_node->top = new_node;
		new_node->bottom = new_node;
	}
	else
	{
		current_first = (t_node *)mode->head_b;
		current_top = current_first->top;
		current_top->bottom = new_node;
		current_first->top = new_node;
		new_node->top = current_top;
		new_node->bottom = current_first;
	}

	mode->head_b = new_node;
	mode->size_b += 1;
}

int	pa(t_mode *mode)
{
	t_node	*node;

	node = cut_headnode_b(mode);
	add_headnode_a(mode, node);
}

int	pb(t_mode *mode)
{
	t_node	*node;

	node = cut_headnode_a(mode);
	add_headnode_b(mode, node);
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