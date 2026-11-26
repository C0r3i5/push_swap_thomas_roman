/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:51:46 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 14:57:11 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	sort_simple(t_mode *mode)
{
	size_t	count_array_loop1;
	size_t	count_array_loop2;
	int	swapped;

	// print_stack(mode);

	count_array_loop1 = -1;
	while (++count_array_loop1 < mode->size_a - 1)
	{
		swapped = 0;
		count_array_loop2 = -1;
		while (++count_array_loop2 < mode->size_a - 1)
		{
			if (mode->head_a->value > mode->head_a->bottom->value)
			{
				sa(mode);
				swapped = 1;
			}
			ra(mode);
		}
		ra(mode);

		// print_stack(mode);

		if (!swapped)
			break ;
	}
}
