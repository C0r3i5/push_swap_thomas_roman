/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:48:12 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 22:00:43 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/// @brief Resolve the effective sorting algorithm based on flags and disorder
/// @param mode Program configuration and operation counters
/// @return The resolved algorithm (SIMPLE, MEDIUM, or COMPLEX)
t_algo    resolve_algo(t_mode *mode)
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

void	sort_simple(t_mode *mode)
{

}

void	sort_medium(t_mode *mode)
{

}

void	sort_complex(t_mode *mode)
{

}

/// @brief Start the resolved sort algo
/// @param mode Program configuration and operation counters
void	start_sort(t_mode *mode)
{
	mode->disorder = compute_disorder(*mode);
	resolve_algo(mode);

	if (mode->disorder == 0.0 || mode->size_a < 2)
		return ;

	if (mode->used_algo == SIMPLE)
		sort_simple(mode);
	else if (mode->used_algo == MEDIUM)
		sort_medium(mode);
	else if (mode->used_algo == COMPLEX)
		sort_complex(mode);
}
