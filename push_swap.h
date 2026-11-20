/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:29:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/20 19:33:38 by twalter          ###   ########.fr       */
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
	size_t			position;
}					t_node;

/// @brief Struct for program mode and counter for bench mode
typedef struct s_mode
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	double	disorder;
	t_algo	algo;
	int		bench_active;
	t_node	*head_a;
	t_node	*head_b;
	size_t	size_a;
	size_t	size_b;
}			t_mode;

int 	parse_arguments(int argc, char **argv, t_mode *mode, t_node **lst_a);

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

#endif
