/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:41 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 12:30:45 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
#include <stdio.h>

static size_t	count_digits_bin(int value)
{
	size_t	count;
	long 	un_value;

	count = 0;
	un_value = (unsigned int)value;
	while (un_value > 0)
	{
		un_value >>= 1;
		count++;
	}
	return (count);
}

static size_t	get_digits_bin(int value, size_t digit)
{
	long 	un_value;

	un_value = (unsigned int)value;
	return ((un_value >> digit) & 1);
}

static int	find_longest_number(t_mode *mode)
{
	t_node	*cur;
	size_t	cur_digit;
	size_t	idx;
	size_t	longest_number_digits;
	int		longest_number_value;

	idx = 0;
	longest_number_digits = 0;
	cur = mode->head_a;
	while (idx < mode->size_a)
	{
		cur_digit = count_digits_bin(cur->value);
		if (cur_digit > longest_number_digits)
		{
			longest_number_digits = cur_digit;
			longest_number_value = cur->value;
		}
		cur = cur->bottom;
		idx++;
	}
	return (longest_number_value);
}

static void	sort_inner(t_mode *mode, size_t idx_digit)
{
	t_node	*cur;
	size_t	idx_list;


	cur = mode->head_a;
	idx_list = 0;
	while (idx_list < mode->size_a)
	{
		if (get_digits_bin(cur->helper, idx_digit) == 0)
			pb(mode);
		else
		{
			ra(mode);
			idx_list++;
		} 
		cur = mode->head_a;
	}
	while (mode->size_b > 0)
		pa(mode);
}

void	sort_complex(t_mode *mode)
{
	size_t	idx_digit;
	size_t	digits;

	idx_digit = 0;
	digits = count_digits_bin(find_longest_number(mode));
	calculate_rank(mode);
	while (idx_digit < digits)
	{
		sort_inner(mode, idx_digit);
		if (compute_disorder(*mode) == 0.0)
			break;
		idx_digit++;
	}
}

