/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:29:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 14:01:47 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <limits.h>

/// @brief Enum with the selectable sort algos
typedef enum e_algo
{
	NONE,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}			t_algo;

/// @brief Struct with the items to sort
typedef struct s_node
{
	int				value;
	struct s_node	*top;
	struct s_node	*bottom;
}					t_node;

/// @brief Struct for program mode and counter for bench mode
typedef struct s_mode
{
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
	double	disorder;
	t_algo	algo;
	int		bench_active;
	void	*head_a;
	void	*head_b;
	long	size_a;
}			t_mode;

int 	parse_arguments(int argc, char **argv, t_mode *mode, t_node **lst_a);

t_node	*new_node(int value);
int		find_dub(t_node **lst, int value);
int		append_unique(t_node **lst_a, t_node *node, t_mode *mode);
double	compute_disorder(t_node *lst, t_mode mode);

#endif
