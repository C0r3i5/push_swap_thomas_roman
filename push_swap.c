/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/19 20:58:58 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node) * 1);
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static t_node *atoi_strict_node(char *arg)
{
	int		idx;
	int		sign;
	int		num_value;
	t_node	*node;

	idx = 0;
	sign = 1;
	num_value = 0;
	while (arg[idx] != '\0')
	{
		if ((arg[idx] == '+' || arg[idx] == '-') && idx == 0)
		{
			if (arg[idx] == '-')
				sign = -1;
			idx++;
		}
		else if (arg[idx] >= '0' && arg[idx] <= '9') 
		{
			num_value = (num_value) * 10 + (arg[idx] - '0');
			idx++;
		} 
		else 
			return (NULL);
	}
	node = new_node(num_value * sign);

	return (node);
}

static int is_flag(char *arg, t_mode *mode)
{
	t_algo	parsed_algo;

	if (!ft_strncmp(arg, "--bench", 8))
	{
		mode->bench_active = 1;
		return (1);
	}

	if (!ft_strncmp(arg, "--simple", 9))
		parsed_algo = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		parsed_algo = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		parsed_algo = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		parsed_algo = ADAPTIVE;
	else
		return (0);

	if (mode->algo != NONE)
		return (-1);
	else
		mode->algo = parsed_algo;

	return (1);
}

static int parse_arguments(int argc, char **argv, t_mode *mode)
{
	int		idx;
	t_node	*new_node;
	int		ret_parse_arg;

	idx = 1;
	while (idx < argc)
	{
		ret_parse_arg = is_flag(argv[idx], mode);
		if (ret_parse_arg == -1)
			return (-1);
		if (ret_parse_arg == 1)
			idx++;
		else
		{
			new_node = atoi_strict_node(argv[idx]);
			if (new_node == NULL)
				return (-1);
			idx++;
		}

	}
	return (0);
}


int	main(int argc, char *argv[])
{
	// t_node	lst_a;
	// t_node	lst_b;
	t_mode	mode;
	// t_node	a;
	// t_node	b;

	// long	count_a;
	// long	count_b;

	// TODO: Check for Arguments (0)
	if (argc < 2)
		return (0);

	ft_bzero(&mode, sizeof(t_mode));
	if (parse_arguments(argc, argv, &mode) == -1)
		return (0); // TODO: Error Ausgabe und free

	printf("Mode: %i, bench: %i", mode.algo, mode.bench_active);

}