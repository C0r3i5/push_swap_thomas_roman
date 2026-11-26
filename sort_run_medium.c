/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rulrich <rulrich@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:52:23 by twalter           #+#    #+#             */
/*   Updated: 2026/11/26 11:08:04 by rulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// loeschen
static int	num_len(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	addr_len(unsigned long long a)
{
	int	len;

	len = 1;
	while (a >= 16)
	{
		a /= 16;
		len++;
	}
	return (len + 2);
}

static void	print_spaces(int n)
{
	while (n-- > 0)
		ft_printf(" ");
}

static void	print_row(int i, t_node *node)
{
	ft_printf("%d", i);
	print_spaces(6 - num_len(i));
	ft_printf("%d", node->value);
	print_spaces(13 - num_len(node->value));
	ft_printf("%p", (void *)node);
	print_spaces(20 - addr_len((unsigned long long)node));
	ft_printf("%d\n", node->helper);
}

static void	print_ring(t_node *head, int size, char *name)
{
	t_node	*current;
	int		i;

	ft_printf("%s (size: %d)\n", name, size);
	if (head == NULL || size <= 0)
	{
		ft_printf("  (leer)\n");
		return ;
	}
	ft_printf("Index ");
	ft_printf("Value        ");
	ft_printf("Address             ");
	ft_printf("Rank\n");
	ft_printf("----- ");
	ft_printf("-----        ");
	ft_printf("-------             ");
	ft_printf("----\n");
	current = head;
	i = 0;
	while (i < size)
	{
		print_row(i, current);
		current = current->bottom;
		i++;
	}
}

void	print_stack(t_mode *mode)
{
	ft_printf("--- Stack-Zustand ---\n");
	print_ring(mode->head_a, mode->size_a, "head_a");
	print_ring(mode->head_b, mode->size_b, "head_b");
	ft_printf("---------------------\n");
}



///////////////



static int ft_chunk_count(size_t size)
{
	int chunk_count;
	int chunk_size;

	chunk_count = 1;
	while (chunk_count * chunk_count < size)
		chunk_count++;

	chunk_size = (size + chunk_count - 1) / chunk_count;

	return (chunk_size);
}

static void	normalize_stack(t_node *stack, int size, size_t max_chunc)
{
	t_node	*current;
	t_node	*other;
	int		rank;
	int		i;
	int		j;

	if (!stack || size <= 0 || max_chunc == 0)
		return ;
	current = stack;
	i = 0;
	while (i < size)
	{
		rank = 0;
		other = stack;
		j = 0;
		while (j < size)
		{
			if (other->value < current->value)
				rank++;
			other = other->bottom;
			j++;
		}
		current->helper = rank / max_chunc;
		current = current->bottom;
		i++;
	}
}

static size_t	find_max_pos_b(t_mode *mode)
{
	t_node	*cur;
	size_t	idx;
	size_t	max_pos;
	int		max_value;

	cur = mode->head_b;
	max_value = cur->value;
	max_pos = 0;
	idx = 0;
	while (idx < mode->size_b)
	{
		if (cur->value > max_value)
		{
			max_value = cur->value;
			max_pos = idx;
		}
		cur = cur->bottom;
		idx++;
	}
	return (max_pos);
}


static void	rotate_b_to_pos(t_mode *mode, size_t pos)
{
	size_t	steps;

	if (mode->size_b == 0 || pos >= mode->size_b)
		return ;
	if (pos <= mode->size_b / 2)
	{
		while (pos > 0)
		{
			rb(mode);
			pos--;
		}
		return ;
	}
	steps = mode->size_b - pos;
	while (steps > 0)
	{
		rrb(mode);
		steps--;
	}
}



void	sort_medium(t_mode *mode)
{
	int	chunk;
	int	buckets;
	int	size;
	int	d;
	int	i;

	size = mode->size_a;
	// ft_printf("[DBG] nach normalize:\n");
	// print_stack(mode);
	if (size <= 1)
		return ;
	chunk = ft_chunk_count(size);
	ft_printf("[DBG] nach normalize:\n");
	print_stack(mode);
	buckets = (size + chunk - 1) / chunk;
	normalize_stack(mode->head_a, size, chunk);

	ft_printf("[DBG] nach normalize:\n");
	print_stack(mode);
	// ft_printf("[DBG] vor BUCKET\n");

	// t_node	*n;
	// int		i;

	// n = mode->head_a;
	// i = 0;
	// while (i < mode->size_a)
	// {
	// 	n->helper = n->helper / chunk;
	// 	n = n->bottom;
	// 	i++;
	// }
	// ft_printf("[DBG] nach BUCKET\n");

	// print_stack(mode);

	d = buckets - 1;
	while (d >= 0)
	{
		i = 0;
		while (i < size)
		{
			if (mode->head_a != NULL && mode->head_a->helper == d)
				pb(mode);
			else
				ra(mode);
			i++;
		}
		ft_printf("[DBG] vor Sortierung \n");
		print_stack(mode);
		while (mode->head_b != NULL)
		{
			rotate_b_to_pos(mode, find_max_pos_b(mode));
			pa(mode);
		}
		ft_printf("[DBG] nach Sortierung \n");
		print_stack(mode);
		d--;
	}
	(void)mode->head_b;
	ft_printf(" ------- \t DONE \t   ------- \n");
}



// void	sort_medium(t_mode *mode)
// {
// 	int d;
// 	int i;


// 	d = ft_chunk_count(mode->size_a);

// 	normalize_stack(mode->head_a, d);

// 	print_stack(mode->head_a);
// 	d--;
// 	while (d >= 0)
// 	{
// 		i = 0;
// 		while (i < mode->size_a)
// 		{
// 			if (mode->head_a->helper == d && mode->head_a->bottom != NULL)
// 				pb(mode);
// 			ra(mode);
// 			i++;
// 		}
// 		while (mode->head_b != NULL)
// 		{
// 			rotate_to_pos(mode, find_insert_pos(mode,mode->head_b->value));
// 			pa(mode);
// 		}
// 		d--;
// 	}

// 	print_stack(mode->head_a);

// 	(void)mode->head_b;

// }





// int ft_find_max(t_mode *stack)
// {
// 	int max_val;

// 	if (stack == NULL)
// 		return (0);

// 	max_val = stack->head_a;
// 	while (stack != NULL)
// 	{
// 		if (stack->value > max_val)
// 			max_val = stack->value;
// 		stack = stack->next;
// 	}
// 	return (max_val);
// }

// int ft_find_min(t_stack *stack)
// {
// 	int min_val;

// 	if (stack == NULL)
// 		return (0);

// 	min_val = stack->value;
// 	while (stack != NULL)
// 	{
// 		if (stack->value < min_val)
// 			min_val = stack->value;
// 		stack = stack->next;
// 	}
// 	return (min_val);
// }



#include <stdio.h>






// size_t	find_insert_pos(t_stack *stack, int val, size_t size)
// {
// 	t_stack	*cur;
// 	t_stack	*next;
// 	size_t	idx;
// 	size_t	min_pos;

// 	if (size < 2 || stack == NULL || stack->next == NULL)
// 		return (0);
// 	cur = stack;
// 	idx = 0;
// 	min_pos = 0;
// 	while (idx < size && cur != NULL)
// 	{
// 		next = cur->next;
// 		if (next == NULL)
// 			next = stack;
// 		if (cur->value < val && val < next->value)
// 			return ((idx + 1) % size);
// 		if (cur->value > next->value)
// 			min_pos = (idx + 1) % size;
// 		cur = cur->next;
// 		idx++;
// 	}
// 	return (min_pos);
// }



// void	rotate_to_pos(t_stack **a, size_t pos, size_t size)
// {
// 	size_t	steps;

// 	if (pos <= size / 2)
// 	{
// 		while (pos-- > 0)
// 			ra(a);
// 		return ;
// 	}
// 	steps = size - pos;
// 	while (steps-- > 0)
// 		rra(a);
// }




// #include <stddef.h> // Für size_t




// void	ft_chunk_sort(t_stack **a, t_stack **b, int size)
// {

// }
