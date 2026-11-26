/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:23 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 14:05:33 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static void	normalize_stack(t_node *stack, int size)
{
	t_node	*current;
	t_node	*other;
	int		rank;
	int		i;
	int		j;

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
		current->helper = rank;
		current = current->bottom;
		i++;
	}
}

static size_t	find_second_max_pos_b(t_mode *mode, size_t max_pos)
{
	t_node	*cur;
	size_t	idx;
	size_t	sec_pos;
	int		sec_val;

	cur = mode->head_b;
	sec_val = -2147483648;
	sec_pos = 0;
	idx = 0;
	while (idx < mode->size_b)
	{
		if (idx != max_pos && cur->value >= sec_val)
		{
			sec_val = cur->value;
			sec_pos = idx;
		}
		cur = cur->bottom;
		idx++;
	}
	return (sec_pos);
}

static void	push_all_to_b(t_mode *mode, int range)
{
	int	i;

	i = 0;
	while (mode->size_a > 0)
	{
		if (mode->head_a->helper <= i)
		{
			pb(mode);
			rb(mode);
			i++;
		}
		else if (mode->head_a->helper <= i + range)
		{
			pb(mode);
			i++;
		}
		else
			ra(mode);
	}
}

static void	push_back_to_a(t_mode *mode)
{
	size_t	max_pos;
	size_t	sec_pos;
	size_t	cost_max;
	size_t	cost_sec;

	while (mode->head_b != NULL)
	{
		max_pos = find_max_pos_b(mode);
		sec_pos = find_second_max_pos_b(mode, max_pos);
		cost_max = max_pos;
		if (max_pos > mode->size_b / 2)
			cost_max = mode->size_b - max_pos;
		cost_sec = sec_pos;
		if (sec_pos > mode->size_b / 2)
			cost_sec = mode->size_b - sec_pos;
		if (mode->size_b > 1 && cost_sec < cost_max)
		{
			rotate_b_to_pos(mode, sec_pos);
			pa(mode);
			rotate_b_to_pos(mode, find_max_pos_b(mode));
			pa(mode);
			sa(mode);
			continue ;
		}
		rotate_b_to_pos(mode, max_pos);
		pa(mode);
	}
}

void	sort_medium(t_mode *mode)
{
	int	size;
	int	range;

	size = mode->size_a;
	if (size <= 1)
		return ;
	normalize_stack(mode->head_a, size);
	range = 15;
	if (size > 100)
		range = 32;
	push_all_to_b(mode, range);
	push_back_to_a(mode);
}

