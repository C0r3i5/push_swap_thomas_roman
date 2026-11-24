/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:51:46 by twalter           #+#    #+#             */
/*   Updated: 2026/11/24 10:57:53 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	sort_simple(t_mode *mode)
{
	int	count_array_loop1;
	int	count_array_loop2;
	int	swapped;

	(void)mode->head_b;
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
		if (!swapped)
			break ;
	}
}
