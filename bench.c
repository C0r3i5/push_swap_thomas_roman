/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:20:46 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 21:38:54 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/// @brief Print the computed disorder percentage (two decimals) to stderr
/// @param disorder Disorder ratio between 0.0 and 1.0
static void	print_disorder(double disorder)
{
	size_t disorder_percent;

	disorder_percent = (size_t)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(disorder_percent / 100), 2);
	ft_putchar_fd('.', 2);
	if (disorder_percent % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(disorder_percent % 100), 2);
	ft_putstr_fd("%\n", 2);
}

/// @brief Print the complexity class to stderr.
/// @param algo Selected sort algo category
static void    print_complexity(t_algo algo)
{
	if (algo == SIMPLE)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (algo == MEDIUM)
		ft_putstr_fd("O(n*sqrt(n))\n", 2);
	else
		ft_putstr_fd("O(n log n)\n", 2);
}

/// @brief Print the selected sort strategy and complexity class to stderr.
/// @param mode Program configuration and operation counters
static void    print_strategy(t_mode mode)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (mode.algo == SIMPLE)
		ft_putstr_fd("Simple / ", 2);
	else if (mode.algo == MEDIUM)
		ft_putstr_fd("Medium / ", 2);
	else if (mode.algo == COMPLEX)
		ft_putstr_fd("Complex / ", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		print_complexity(mode.used_algo);
		return ;
	}
	print_complexity(mode.algo);
}

/// @brief Print a combination of name and (int) counter to stderr.
/// @param name Printed name of the operation
/// @param count Counted use of the operation
static void    print_operators(char *name, size_t count)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd((int)count, 2);
}

/// @brief Print bench information to stderr if bench mode is active
/// @param mode Program configuration and operation counters
void    print_bench(t_mode mode)
{
	size_t    total;

	if (!mode.bench_active)
		return ;
	total = mode.sa + mode.sb + mode.ss + mode.pa + mode.pb
		+ mode.ra + mode.rb + mode.rr + mode.rra + mode.rrb + mode.rrr;
	print_disorder(mode.disorder);
	print_strategy(mode);
	print_operators("[bench] total_ops: ", total);
	ft_putchar_fd('\n', 2);
	print_operators("[bench] sa: ", mode.sa);
	print_operators(" sb: ", mode.sb);
	print_operators(" ss: ", mode.ss);
	print_operators(" pa: ", mode.pa);
	print_operators(" pb: ", mode.pb);
	ft_putchar_fd('\n', 2);
	print_operators("[bench] ra: ", mode.ra);
	print_operators(" rb: ", mode.rb);
	print_operators(" rr: ", mode.rr);
	print_operators(" rra: ", mode.rra);
	print_operators(" rrb: ", mode.rrb);
	print_operators(" rrr: ", mode.rrr);
	ft_putchar_fd('\n', 2);
}
