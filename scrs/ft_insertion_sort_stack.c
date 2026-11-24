/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:05:36 by rulrich           #+#    #+#             */
/*   Updated: 2026/11/24 13:53:47 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_helper.c"



void insertion_sort_stack(t_stack **a, t_stack **b, int size)
{
	int count_array_loop1;

	count_array_loop1 = 0;
	while (*a != NULL && count_array_loop1 < size)
	{
		if ((*a)->next != NULL && (*a)->value < (*a)->next->value)
		{
			ra(a);
		}
		else if (*b == NULL || (*b)->value < (*a)->value)
		{
			pb(a, b);
			count_array_loop1++;
		}
		else if ((*b)->next != NULL)
		{
			ra(b);
		}
		else
		{
			ra(b);
		}
	}



	// while(*a != NULL)


	// while(*a != NULL)
	// {
	// 	if ((*a)->next != NULL && (*a)->value < (*a)->next->value)
	// 		sa(a);
	// 	else if (*b == NULL || (*b)->value < (*a)->value)
	// 		pb(a,b);
	// 	else if (*a != NULL
	// 			&& *b != NULL
	// 			&& (*b)->next != NULL
	// 			&& (*a)->value < (*b)->value
	// 			&& (*a)->value > (*b)->next->value)
	// 	{
	// 		ra(b);
	// 		pb(a,b);
	// 	}
	// 	else
	// 		ra(a);
	// }
	// while (++count_array_loop1 < size - 1)
	// {
	// 	// if ((*a)->value > (*a)->next->value)
	// 	pb(a,b);

	// }
}
