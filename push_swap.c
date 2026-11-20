/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:36:43 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 12:38:21 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

/// @brief Free split list
/// @param parts List with items
static void	free_split(char **parts)
{
	size_t	idx;

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
/// @brief Create a new unconnected node with the value
/// @param value Signed Int value
/// @return The new node or NULL
static t_node	*new_node(int value)
{
	t_node	*node;

	printf("T3 %i\n", value);
	node = malloc(sizeof(t_node) * 1);
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

/// @brief Check if the new value is already in the list
/// @param lst The existing list
/// @param value The new value to check
/// @return Dublicate 1, unique 0
static int	find_dub(t_node **lst, int value) 
{
	t_node *node_current;
	t_node *node_start;
	
	if (lst == NULL) 
		return (0);

	node_start = *lst;
	if (node_start == NULL)
		return (0);

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

/// @brief Append new node to a existing list if value is unique
/// @param lst_a The existing list with values
/// @param node The new node canidate
/// @return Error -1, Success 0
static int	append_unique(t_node **lst_a, t_node *node, t_mode *mode)
{
	t_node *node_current_first;
	t_node *node_start;

	if (*lst_a == NULL)
	{
		mode->head_a = node;
		node->next = node;
		node->prev = node;
		*lst_a = node;
		mode->size_a = 1;
		return (0);
	}
	node_start = (t_node *)mode->head_a;
	if (find_dub(lst_a, node->value) == 1)
		return (-1);
	
	node_current_first = node_start->next;
	node_start->next = node;
	node->prev = node_start;
	node->next = node_current_first;
	node_current_first->prev = node;
	mode->size_a += 1;
	return (0);
}

/// @brief Convert a string to a number (if possible) and create a new node
/// @param arg Argument, should be a signed int number
/// @return A new node element or NULL if an error
static t_node *atoi_strict_node(char *arg)
{
	size_t	idx;
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

/// @brief Parse a String, split it and commission atoi and cappend_unique.
/// @param arg A string argument
/// @param lst_a List A with the current values
/// @return Error -1 
static int	parse_number_arg(char *arg, t_node **lst_a, t_mode *mode)
{
	char	**parts;
	size_t	idx;
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
		if (node == NULL || append_unique(lst_a, node, mode) == -1)
		{
			free_split(parts);
			free(node);
			return (-1);
		}
		idx++;
	}
	return (0);
}

/// @brief Checks whether the passed argument is a configuration flag
/// @param arg The argument to check
/// @param mode The list for setting the mode 
/// @return Is flag (1) or not (0), -1 if a invalid arguemnt is passed
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

/// @brief Start the check of every argument for flag or int number
/// @param argc Number of passed arguments 
/// @param argv List of the arguments
/// @param mode The list for setting the mode 
/// @return 0 if all arguements are valid, -1 if a invalid arg is in the list
static int parse_arguments(int argc, char **argv, t_mode *mode, t_node **lst_a)
{
	size_t	idx;
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
			ret_parse_arg = parse_number_arg(argv[idx], lst_a, mode);
			if (ret_parse_arg == -1)
				return (-1);
			idx++;
		}
	}
	return (0);
}

static double	compute_disorder(t_node *lst, t_mode mode)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node *node_current_1;
	t_node *node_current_2;
	t_node *node_start;
	
	mistakes = 0;
	total_pairs = 0;



	node_current_1 = node_start->prev;
	while (node_current_1 != node_start)
	{
		node_current_2 = node_start->prev->prev;
		while (node_current_2 != node_start)
		{
			total_pairs += 1;
			printf("%d > %d\n", node_current_1->value, node_current_2->value);
			if (node_current_1->value > node_current_2->value)
				mistakes += 1;
			node_current_2 = node_current_2->prev;
		}
		node_current_1 = node_current_1->prev;
	}
	return((double)mistakes / total_pairs);
}

int	main(int argc, char *argv[])
{
	t_node	*lst_a;
	t_node	*lst_b;
	t_mode	mode;

	printf("Test\n");
	// TODO: Check for Arguments (0)
	if (argc < 2)
		return (0);

	ft_bzero(&mode, sizeof(t_mode));
	lst_a = NULL;
	lst_b = NULL;
	if (parse_arguments(argc, argv, &mode, &lst_a) == -1)
	{
		printf("-1\n");
		return (0); // TODO: Error Ausgabe und free
	}
	mode.disorder = compute_disorder(lst_a, mode);

	printf("Mode: %i, bench: %i, head_a: %p, size: %lu, disorder: %f\n", mode.algo, mode.bench_active, mode.head_a, mode.size_a, mode.disorder);
	printf("1: %i %p %p %p\n", lst_a->value, lst_a, lst_a->prev, lst_a->next);
	printf("2: %i %p %p %p\n", lst_a->prev->value, lst_a->prev, lst_a->prev->prev, lst_a->prev->next);
}