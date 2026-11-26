/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_outs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:47:39 by rulrich           #+#    #+#             */
/*   Updated: 2026/11/26 14:43:46 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_print_outs.h"

static int	num_len(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	addr_len(unsigned long long a)
{
	int	len;

	len = 1;
	while (a >= 16)
	{
		a /= 16;
		len++;
	}
	return (len + 2);
}

static void	print_spaces(int n)
{
	while (n-- > 0)
		ft_printf(" ");
}

static void	print_row(int i, t_node *node)
{
	ft_printf("%d", i);
	print_spaces(6 - num_len(i));
	ft_printf("%d", node->value);
	print_spaces(13 - num_len(node->value));
	ft_printf("%p", (void *)node);
	print_spaces(20 - addr_len((unsigned long long)node));
	ft_printf("%d\n", node->helper);
}

static void	print_ring(t_node *head, int size, char *name)
{
	t_node	*current;
	int		i;

	ft_printf("%s (size: %d)\n", name, size);
	if (head == NULL || size <= 0)
	{
		ft_printf("  (leer)\n");
		return ;
	}
	ft_printf("Index ");
	ft_printf("Value        ");
	ft_printf("Address             ");
	ft_printf("Rank\n");
	ft_printf("----- ");
	ft_printf("-----        ");
	ft_printf("-------             ");
	ft_printf("----\n");
	current = head;
	i = 0;
	while (i < size)
	{
		print_row(i, current);
		current = current->bottom;
		i++;
	}
}

void	print_stack(t_mode *mode)
{
	ft_printf("--- Stack-Zustand ---\n");
	print_ring(mode->head_a, mode->size_a, "head_a");
	print_ring(mode->head_b, mode->size_b, "head_b");
	ft_printf("---------------------\n");
}
