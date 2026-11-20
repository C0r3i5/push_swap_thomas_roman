/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 13:28:16 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

/// @brief Calculate a number between 0 and 1 that tells how far your initial
/// stack a is from being sorted.
/// @param lst List A with the current values
/// @param mode The list for setting the mode 
/// @return If the numbers are already in the right order, the disorder is 0. 
/// If they are in the worst possible order, the disorder is 1.
static double	compute_disorder(t_node *lst, t_mode mode)
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
	while (node_current_1->next != mode.head_a || total_pairs == 0)
	{
		node_current_2 = node_current_1;
		while (node_current_2->next != mode.head_a || idx++ == 0)
		{
			total_pairs += 1;
			printf("%d > %d\n", node_current_1->value, node_current_2->next->value);
			if (node_current_1->value > node_current_2->next->value)
				mistakes++;
			node_current_2 = node_current_2->next;
		}
		idx = 0;
		node_current_1 = node_current_1->next;
	}
	return((double)mistakes / total_pairs);
}

int	main(int argc, char *argv[])
{
	t_node	*lst_a;
	t_node	*lst_b;
	t_mode	mode;

	printf("Test\n");
	// TODO: Check for Arguments (0)
	if (argc < 2)
		return (0);

	ft_bzero(&mode, sizeof(t_mode));
	lst_a = NULL;
	lst_b = NULL;
	if (parse_arguments(argc, argv, &mode, &lst_a) == -1)
	{
		printf("-1\n");
		return (0); // TODO: Error Ausgabe und free
	}
	mode.disorder = compute_disorder(lst_a, mode);

	printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	printf("1: %i %p %p %p\n", lst_a->value, lst_a, lst_a->prev, lst_a->next);
	printf("2: %i %p %p %p\n", lst_a->next->value, lst_a->next, lst_a->next->prev, lst_a->next->next);
}