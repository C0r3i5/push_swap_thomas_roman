/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:23 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 13:08:07 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chunk_count(size_t size)
{
	int	chunk_count;
	int	chunk_size;

	chunk_count = 1;
	while (chunk_count * chunk_count < size)
		chunk_count++;
	chunk_size = (size + chunk_count - 1) / chunk_count;
	return (chunk_size);
}

static void	normalize_stack(t_node *stack, int size, size_t max_chunc)
{
	t_node	*current;
	t_node	*other;
	int		rank;
	int		i;
	int		j;

	if (!stack || size <= 0 || max_chunc == 0)
		return ;
	current = stack;
	i = 0;
	while (i < size)
	{
		rank = 0;
		other = stack;
		j = 0;
		while (j < size)
		{
			if (other->value < current->value)
				rank++;
			other = other->bottom;
			j++;
		}
		current->helper = rank / max_chunc;
		current = current->bottom;
		i++;
	}
}

void	sort_medium(t_mode *mode)
{
	int	chunk;
	int	size;
	int	d;
	int	i;

	size = mode->size_a;

	if (size <= 1)
		return ;
	chunk = ft_chunk_count(size);
	normalize_stack(mode->head_a, size, chunk);
	d = ((size + chunk - 1) / chunk) - 1;
	while (d >= 0)
	{
		i = 0;
		while (i < size)
		{
			if (mode->head_a != NULL && mode->head_a->helper == d)
				pb(mode);
			else
				ra(mode);
			i++;
		}
		while (mode->head_b != NULL)
		{
			rotate_b_to_pos(mode, find_max_pos_b(mode));
			pa(mode);
		}
		d--;
	}
}
