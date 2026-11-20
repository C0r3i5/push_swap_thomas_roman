/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 13:56:39 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

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