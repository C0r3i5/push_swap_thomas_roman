/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:41 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 07:32:02 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
#include <stdio.h>
static size_t	count_digits(int value)
{
	size_t	idx;

	idx = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		value = -value;
		idx++;
	}
	while (value > 0)
	{
		value = value / 10;
		idx++;
	}
	return (idx);
}



static size_t	find_longest_number(t_mode *mode)
{
	t_node	*cur;
	size_t	cur_digit;
	size_t	idx;
	size_t	longest_number_digits;

	idx = 0;
	longest_number_digits = 0;
	cur = mode->head_a;
	while (idx < mode->size_a)
	{
		cur_digit = count_digits(cur->value);
		if (cur_digit > longest_number_digits)
			longest_number_digits = cur_digit;
		cur = cur->bottom;
		idx++;
	}
	return (longest_number_digits);
}

static int	get_digit(int value, size_t pos)
{
	size_t	idx;
	int		multip;

	idx = 0;
	multip = 1;
	while (idx < pos)
	{
		multip = multip * 10;
		idx++;
	}
	return (value / multip % 10);
}

void	sort_complex(t_mode *mode)
{
	size_t	idx_digit;
	size_t	idx_list;
	t_node	*cur;

	idx_digit = 0;
	
	while (idx_digit < find_longest_number(mode))
	{
		cur = mode->head_a;
		idx_list = 0;
		while (idx_list < mode->head_a)
		{
			cur->helper = get_digit(cur->value, idx_digit);
			cur = cur->bottom;
			idx_list++;
		}

		idx_list = 0;
		while (idx_list < mode->head_a)
			
			cur = cur->bottom;
			idx_list++;
		}





		idx_digit++;
	}
}

