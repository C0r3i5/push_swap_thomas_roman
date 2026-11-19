/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/19 15:56:15 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

static int atoi_strict(char *arg)
{
	
}

static int is_flag(char *arg, t_mode *mode)
{
	if (!ft_strncmp(arg, "--simple", 8))
		mode->algo = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 8))
		mode->algo = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 9))
		mode->algo = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 10))
		mode->algo = ADAPTIVE;
	else if (!ft_strncmp(arg, "--bench", 7))
		mode->bench_active = 1;
	else
		return (0);

	return (1);
}

static int parse_arguments(int argc, char **argv, t_mode *mode)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		is_flag(argv[i], mode);
		i++;
	}
	return (0);
}


int	main(int argc, char *argv[])
{
	t_node	lst_a;
	t_node	lst_b;
	t_mode	mode;
	t_node	a;
	t_node	b;

	long	count_a;
	long	count_b;

	// TODO: Check for Arguments (0)
	if (argc < 2)
		return (0);

	ft_bzero(&mode, sizeof(t_mode));
	parse_arguments(argc, argv, &mode);

	printf("Mode: %i, bench: %i", mode.algo, mode.bench_active);

}