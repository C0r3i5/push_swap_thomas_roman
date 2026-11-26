/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:41 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 10:54:05 by twalter          ###   ########.fr       */
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
	size_t	count;
	long 	un_value;

	count = 0;
	un_value = (unsigned int)value;
	// printf("T %ld\n", ((un_value >> digit) & 1));

	// while (un_value > 0)
	// {
	// 	un_value = un_value >> 1;
	// 	if (count == digit - 1)
	// 		return (un_value & 1);
	// 	count++;
	// }
	
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


// static int	get_digit(int value, size_t pos)
// {
// 	size_t	idx;
// 	int		multip;

// 	idx = 0;
// 	multip = 1;
// 	while (idx < pos)
// 	{
// 		multip = multip * 10;
// 		idx++;
// 	}
// 	return (value / multip % 10);
// }

void	sort_complex(t_mode *mode)
{


	// printf("1 %d\n", find_longest_number(mode));
	// printf("2 %lu\n", count_digits_bin(1));
	// printf("3 %lu\n", get_digits_bin(-1, 0));
	// printf("3 %lu\n", get_digits_bin(-1, 1));

	// printf("T %d\n", ((2 >> 0) & 1));
	// printf("T %d\n", ((2 >> 1) & 1));
	// printf("T %d\n", ((2 >> 2) & 1));
	
	size_t	idx_digit;
	size_t	idx_list;
	t_node	*cur;
	size_t	max_digits;

	idx_digit = 0;
	
	max_digits = count_digits_bin(find_longest_number(mode));
	printf("Max digits %zu mit longest %d\n", max_digits, find_longest_number(mode));
	while (idx_digit < max_digits)
	{
		cur = mode->head_a;
		idx_list = 0;
		while (idx_list < mode->size_a)
		{
			printf("SizeA: %zu, Value %d, digit %zu\n", mode->size_a, cur->value, get_digits_bin(cur->value, idx_digit));
			if (cur->value > 0)
			{
				if (get_digits_bin(cur->value, idx_digit) == 0)
					pb(mode);
				else
				{
					ra(mode);
					idx_list++;
				} 
			} 
			else
			{
				if (get_digits_bin(cur->value, idx_digit) == 1)
					pb(mode);
				else
				{
					ra(mode);
					idx_list++;
				} 
			}
			

			cur = mode->head_a;
			
		}
		while (mode->size_b > 0)
		{
			// printf("T: %d\n", mode->head_b->value);
			pa(mode);
		}


idx_list = 0;
cur = mode->head_a;
while (idx_list < mode->size_a)
{	
	printf("Liste %d\n", cur->value);
	idx_list++;
	cur = cur->bottom;
}


		idx_digit++;
	}


	idx_list = 0;
	cur = mode->head_a;
	while (idx_list < mode->size_a)
	{	
		printf("Liste %d\n", cur->value);
		idx_list++;
		cur = cur->bottom;
	}

}

