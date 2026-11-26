/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:29:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 12:49:43 by twalter          ###   ########.fr       */
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

/**
 * @brief Struct with the items to sort.
 *
 * Each node stores one integer of the input and links to its neighbours
 * in the stack.
 */
typedef struct s_node
{
	/** Integer value stored in this node. */
	int				value;
	/** Pointer to the node above this one in the stack. */
	struct s_node	*top;
	/** Pointer to the node below this one in the stack. */
	struct s_node	*bottom;
	/** Index of this node's position within its stack. */
	size_t			position;
	int				helper;

}					t_node;

/**
 * @brief Holds the program state of push_swap.
 *
 * Contains the counters for each stack operation, the disorder value,
 * the requested and the used sorting algorithm, the bench mode flag,
 * the heads of both stacks and their sizes.
 */
typedef struct s_mode
{
	/** Number of sa operations (swap top two of stack a). */
	size_t	sa;
	/** Number of sb operations (swap top two of stack b). */
	size_t	sb;
	/** Number of ss operations (sa and sb at once). */
	size_t	ss;
	/** Number of pa operations (push top of b to a). */
	size_t	pa;
	/** Number of pb operations (push top of a to b). */
	size_t	pb;
	/** Number of ra operations (rotate a up). */
	size_t	ra;
	/** Number of rb operations (rotate b up). */
	size_t	rb;
	/** Number of rr operations (ra and rb at once). */
	size_t	rr;
	/** Number of rra operations (reverse rotate a). */
	size_t	rra;
	/** Number of rrb operations (reverse rotate b). */
	size_t	rrb;
	/** Number of rrr operations (rra and rrb at once). */
	size_t	rrr;
	/** Measure of how unsorted the input numbers are. */
	double	disorder;
	/** Sorting algorithm requested by the user. */
	t_algo	algo;
	/** Sorting algorithm that was actually applied. */
	t_algo	used_algo;
	/** Flag: non-zero if bench mode is enabled. */
	int		bench_active;
	/** Pointer to the first node of stack a. */
	t_node	*head_a;
	/** Pointer to the first node of stack b. */
	t_node	*head_b;
	/** Number of elements currently in stack a. */
	size_t	size_a;
	/** Number of elements currently in stack b. */
	size_t	size_b;
}			t_mode;

int	parse_arguments(int argc, char **argv, t_mode *mode, t_node **lst_a);

t_node	*new_node(int value);
int		find_dub(t_node **lst, int value);
int		append_unique(t_node **lst_a, t_node *node, t_mode *mode);
double	compute_disorder(t_mode mode);

void	sa(t_mode *mode);
void	sb(t_mode *mode);
void	ss(t_mode *mode);

void	ra(t_mode *mode);
void	rb(t_mode *mode);
void	rr(t_mode *mode);

void	rra(t_mode *mode);
void	rrb(t_mode *mode);
void	rrr(t_mode *mode);

void	pa(t_mode *mode);
void	pb(t_mode *mode);

void	heal_node_list(t_node **head, size_t *size);

void	print_bench(t_mode mode);

void	start_sort(t_mode *mode);
void	sort_simple(t_mode *mode);
void	sort_medium(t_mode *mode);
void	sort_complex(t_mode *mode);
void	sort_adaptive(t_mode *mode);

void rotate_to_pos(t_mode *mode, size_t pos);
size_t find_insert_pos(t_mode *mode, int val);
void	calculate_rank(t_mode *mode);

/**
 * find_max_pos_b - Finds the index of the maximum value in stack B.
 * @mode: Program state containing stack B and its size.
 *
 * Return: Zero-based index of the maximum-value node in stack B.
 *         Requires stack B to be non-empty.
 */
size_t	find_max_pos_b(t_mode *mode);

/**
 * @brief Rotates stack B to bring the element at the given index to the top.
 *
 * Calculates the shortest rotation path based on the stack size. If the target
 * position is in the upper half (or middle), it rotates upwards using `rb`.
 * Otherwise, it rotates downwards using `rrb`. Does nothing if stack B is empty
 * or if the target position is out of bounds.
 *
 * @param mode Pointer to the main structure containing stack B and its size.
 * @param pos  The 0-based index of the target element in stack B.
 */
void	rotate_b_to_pos(t_mode *mode, size_t pos);

#endif
