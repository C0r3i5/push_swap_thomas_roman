/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:19:35 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 13:55:03 by twalter          ###   ########.fr       */
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
int parse_arguments(int argc, char **argv, t_mode *mode, t_node **lst_a)
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