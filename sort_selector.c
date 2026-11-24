/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:48:12 by twalter           #+#    #+#             */
/*   Updated: 2026/11/24 10:30:57 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/// @brief Resolve the effective sorting algorithm based on flags and disorder
/// @param mode Program configuration and operation counters
/// @return The resolved algorithm (SIMPLE, MEDIUM, or COMPLEX)
static t_algo    resolve_algo(t_mode *mode)
{
	if (mode->algo == NONE)
		mode->algo = ADAPTIVE;
	if (mode->algo != ADAPTIVE)
	{
		mode->used_algo = mode->algo;
		return (mode->used_algo);
	}
	if (mode->disorder < 0.2)
		mode->used_algo = SIMPLE;
	else if (mode->disorder < 0.5)
		mode->used_algo = MEDIUM;
	else
		mode->used_algo = COMPLEX;
	return (mode->used_algo);
}

/// @brief Sort stack a when it contains three nodes
/// @param mode Program configuration and operation counters
static void	sort_3(t_mode *mode)
{
	int	a;
	int	b;
	int	c;

	a = mode->head_a->value;
	b = mode->head_a->bottom->value;
	c = mode->head_a->top->value;
	if (a > b && a > c)
		ra(mode);
	else if (b > a && b > c)
		rra(mode);
	if (mode->head_a->value > mode->head_a->bottom->value)
		sa(mode);
}

/// @brief Find the position of the smallest value in stack a
/// @param mode Program configuration and operation counters
/// @return Zero-based index of the minimum node in stack a
static size_t	get_min_pos(t_mode *mode)
{
	t_node	*cur;
	int		min_val;
	size_t	min_pos;
	size_t	idx;

	cur = mode->head_a;
	min_val = cur->value;
	min_pos = 0;
	idx = 0;
	while (idx < mode->size_a)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_pos = idx;
		}
		cur = cur->bottom;
		idx++;
	}
	return (min_pos);
}

/// @brief Sort stack a when it contains four or five nodes
/// @param mode Program configuration and operation counters
static void	sort_4_5(t_mode *mode)
{
	size_t	min_pos;

	while (mode->size_a > 3)
	{
		min_pos = get_min_pos(mode);
		if (min_pos <= mode->size_a / 2)
		{
			while (min_pos-- > 0)
				ra(mode);
		}
		else
		{
			while (min_pos++ < mode->size_a)
				rra(mode);
		}
		pb(mode);
	}
	sort_3(mode);
	while (mode->size_b > 0)
		pa(mode);
}

/// @brief Start the resolved sort algo and order special cases
/// @param mode Program configuration and operation counters
void	start_sort(t_mode *mode)
{
	mode->disorder = compute_disorder(*mode);
	resolve_algo(mode);

	if (mode->disorder == 0.0 || mode->size_a < 2)
		return ;

	if (mode->size_a == 2
		&& mode->head_a->value > mode->head_a->bottom->value)
		sa(mode);
	else if (mode->size_a == 3)
		sort_3(mode);
	else if (mode->size_a <= 5)
		sort_4_5(mode);
	else if (mode->used_algo == SIMPLE)
		sort_simple(mode);
	else if (mode->used_algo == MEDIUM)
		sort_medium(mode);
	else if (mode->used_algo == COMPLEX)
		sort_complex(mode);
}
