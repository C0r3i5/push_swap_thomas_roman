/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 19:58:28 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

static void free_stack(t_node **head, size_t *size)
{
	t_node *node_current;
	t_node *node_head;
	t_node *node_next;

	if (head == NULL || *head == NULL)
		return ;
	node_head = *head;
	node_current = node_head->bottom;
	while (node_current != node_head)
	{
		node_next = node_current->bottom;
		free(node_current);
		node_current = node_next;
	}
	free(node_head);
	*head = NULL;
	if (size != NULL)
		*size = 0;
}

int	main(int argc, char *argv[])
{
	t_node	*lst_a;
	// t_node	*lst_b;
	t_mode	mode;
	t_node  *node;

	printf("Test\n");
	// TODO: Check for Arguments (0)
	if (argc < 2)
		return (0);

	ft_bzero(&mode, sizeof(t_mode));
	lst_a = NULL;
	// lst_b = NULL;
	if (parse_arguments(argc, argv, &mode, &lst_a) == -1)
	{
		ft_putendl_fd("Error", 2);
		free_stack(&mode.head_a, &mode.size_a);
		return (1);
	}
	mode.disorder = compute_disorder(mode);

	node = (t_node *)mode.head_a;
	printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	printf("%lu: %i %p %p %p\n", node->position, node->value, node, node->top, node->bottom);
	printf("%lu: %i %p %p %p\n", node->bottom->position, node->bottom->value, node->bottom, node->bottom->top, node->bottom->bottom);
	printf("%lu: %i %p %p %p\n", node->bottom->bottom->position, node->bottom->bottom->value, node->bottom->bottom, node->bottom->bottom->top, node->bottom->bottom->bottom);

	ra(&mode);
	heal_node_list(&mode.head_a, &mode.size_a);

	node = (t_node *)mode.head_a;
	printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	printf("%lu: %i %p %p %p\n", node->position, node->value, node, node->top, node->bottom);
	printf("%lu: %i %p %p %p\n", node->bottom->position, node->bottom->value, node->bottom, node->bottom->top, node->bottom->bottom);
	printf("%lu: %i %p %p %p\n", node->bottom->bottom->position, node->bottom->bottom->value, node->bottom->bottom, node->bottom->bottom->top, node->bottom->bottom->bottom);

	ra(&mode);
	heal_node_list(&mode.head_a, &mode.size_a);
	
	node = (t_node *)mode.head_a;
	printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	printf("%lu: %i %p %p %p\n", node->position, node->value, node, node->top, node->bottom);
	printf("%lu: %i %p %p %p\n", node->bottom->position, node->bottom->value, node->bottom, node->bottom->top, node->bottom->bottom);
	printf("%lu: %i %p %p %p\n", node->bottom->bottom->position, node->bottom->bottom->value, node->bottom->bottom, node->bottom->bottom->top, node->bottom->bottom->bottom);

	free_stack(&mode.head_a, &mode.size_a);
	free_stack(&mode.head_b, &mode.size_b);
}