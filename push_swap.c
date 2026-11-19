/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/19 22:12:46 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

static void	free_split(char **parts)
{
	int	idx;

	idx = 0;
	if (parts == NULL)
		return ;
	while (parts[idx] != NULL)
	{
		free(parts[idx]);
		idx++;
	}
	free(parts);
}

static int	find_dub(t_node *lst, int value) 
{
	t_node *node_current;
	t_node *node_start;
	
	if (lst == NULL) 
		return (0);
	node_start = lst;
	if (node_start->value == value)
		return (1);
	node_current = node_start->prev;
	while (node_current != node_start)
	{
		if (value == node_current->value)
			return (1);
		node_current = node_current->prev;
	}
	return (0);
}

static int	append_unique(t_node **lst_a, t_node *node)
{
	t_node *node_current;
	t_node *node_start;

	if (*lst_a == NULL)
	{
		node->next = node;
		node->prev = node;
		*lst_a = node;
		return (0);
	}
	node_start = *lst_a;
	if (find_dub(node_start, node->value) == 1)
		return (-1);
	node_current = node_start->next;
	node_start->next = node;
	node->prev = node_start;
	node->next = node_current;
	node_current->prev = node;
	return (0);
}

static int	parse_number_arg(char *arg, t_node **lst_a)
{
	char	**parts;
	int		idx;
	t_node	*node;

	parts = ft_split(arg, ' ');
	idx = 0;
	if (parts == NULL || parts[0] == NULL)
	{
		free_split(parts);
		return (-1);
	}
	while (parts[idx] != NULL)
	{
		node = atoi_strict_node(parts[idx]);
		if (node == NULL || append_unique(lst_a, node) == -1)
		{
			free_split(parts);
			free(node);
			return (-1);
		}
		idx++;
	}
}

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
	long	num_value;

	idx = 0;
	sign = 1;
	num_value = 0;
	if ((arg[idx] == '+' || arg[idx] == '-'))
	{
		if (arg[idx] == '-')
			sign = -1;
		idx++;
	}
	if (arg[idx] == '\0')
		return (NULL);
	while (arg[idx] != '\0')
	{
		if (arg[idx] < '0' || arg[idx] > '9')
			return (NULL);
		num_value = (num_value) * 10 + (arg[idx] - '0');
		idx++;
		if (num_value * sign > INT_MAX || num_value * sign < INT_MIN)
			return (NULL);
	}
	return (new_node(num_value * sign));
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