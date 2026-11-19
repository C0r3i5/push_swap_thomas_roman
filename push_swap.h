/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 13:29:16 by twalter           #+#    #+#             */
/*   Updated: 2026/11/19 15:00:00 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"

/// @brief Enum with the selectable sort algos
typedef enum e_algo
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}			t_algo;

/// @brief Struct with the items to sort
typedef struct s_node
{
	int				*value;
	struct s_list	*prev;
	struct s_list	*next;
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
	float	disorder;
	t_algo	algo;
	int		bench_active;
}			t_mode;

#endif