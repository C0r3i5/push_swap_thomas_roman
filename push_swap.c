/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 09:33:29 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

/// @brief Free all nodes in the circular list and reset head and size.
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter to update
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


void ft_debug_print_mode_list(t_mode *mode)
{
    t_node *node;
    size_t i;

    if (mode == NULL)
        return;

    printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n",
        mode->algo,
        mode->bench_active,
        (void *)mode->head_a,
        mode->size_a,
        mode->disorder);

    node = (t_node *)mode->head_a;
    i = 0;
    while (node != NULL && i < mode->size_a)
    {
        printf("%lu: %i %p %p %p\n",
            node->position,
            node->value,
            (void *)node,
            (void *)node->top,
            (void *)node->bottom);
        node = node->bottom;
        i++;
    }
}


int	main(int argc, char *argv[])
{
	t_node	*lst_a;
	t_mode	mode;
	t_node  *node;

	if (argc < 2)
		return (0);

	ft_bzero(&mode, sizeof(t_mode));
	lst_a = NULL;
	if (parse_arguments(argc, argv, &mode, &lst_a) == -1)
	{
		ft_putendl_fd("Error", 2);
		free_stack(&mode.head_a, &mode.size_a);
		return (1);
	}
	if (mode.size_a == 0)
		return (0);

	// start_sort(&mode);

	ft_debug_print_mode_list(&mode);
	sort_medium(&mode);



	// node = (t_node *)mode.head_a;
	// printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	// printf("%lu: %i %p %p %p\n", node->position, node->value, node, node->top, node->bottom);
	// printf("%lu: %i %p %p %p\n", node->bottom->position, node->bottom->value, node->bottom, node->bottom->top, node->bottom->bottom);
	// printf("%lu: %i %p %p %p\n", node->bottom->bottom->position, node->bottom->bottom->value, node->bottom->bottom, node->bottom->bottom->top, node->bottom->bottom->bottom);

	// ra(&mode);
	// heal_node_list(&mode.head_a, &mode.size_a);

	// node = (t_node *)mode.head_a;
	// printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	// printf("%lu: %i %p %p %p\n", node->position, node->value, node, node->top, node->bottom);
	// printf("%lu: %i %p %p %p\n", node->bottom->position, node->bottom->value, node->bottom, node->bottom->top, node->bottom->bottom);
	// printf("%lu: %i %p %p %p\n", node->bottom->bottom->position, node->bottom->bottom->value, node->bottom->bottom, node->bottom->bottom->top, node->bottom->bottom->bottom);

	// ra(&mode);
	// heal_node_list(&mode.head_a, &mode.size_a);

	// node = (t_node *)mode.head_a;
	// printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	// printf("%lu: %i %p %p %p\n", node->position, node->value, node, node->top, node->bottom);
	// printf("%lu: %i %p %p %p\n", node->bottom->position, node->bottom->value, node->bottom, node->bottom->top, node->bottom->bottom);
	// printf("%lu: %i %p %p %p\n", node->bottom->bottom->position, node->bottom->bottom->value, node->bottom->bottom, node->bottom->bottom->top, node->bottom->bottom->bottom);



	print_bench(mode);
	free_stack(&mode.head_a, &mode.size_a);
	free_stack(&mode.head_b, &mode.size_b);
}
