/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 14:44:48 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Free all nodes in the circular list and reset head and size.
/// @param head Pointer to the head node of the circular list
/// @param size Pointer to the stack size counter to update
static void	free_stack(t_node **head, size_t *size)
{
	t_node	*node_current;
	t_node	*node_head;
	t_node	*node_next;

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
	t_mode	mode;

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
	start_sort(&mode);
	print_bench(mode);
	free_stack(&mode.head_a, &mode.size_a);
	free_stack(&mode.head_b, &mode.size_b);
}
