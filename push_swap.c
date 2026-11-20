/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 19:33:55 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

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
		printf("-1\n");
		return (0); // TODO: Error Ausgabe und free
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

}