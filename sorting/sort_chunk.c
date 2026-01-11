/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:12:41 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:37:59 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	optimal_rotate(t_node **stack, int pos)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(stack, 1);
	}
	else
	{
		while (pos++ < size)
			rrb(stack, 1);
	}
}

void	push_chunks(t_node **a, t_node **b)
{
	int	i;
	int	range;

	i = 0;
	if (stack_size(*a) <= 100)
		range = 15;
	else
		range = 40;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}

static void	tmp_push(t_node **a, t_node **b, int max, int pos_prev)
{
	optimal_rotate(b, pos_prev);
	pa(a, b, 1);
	optimal_rotate(b, get_pos(*b, max));
	pa(a, b, 1);
	sa(a, 1);
}

void	push_back_to_a(t_node **a, t_node **b)
{
	int	max;
	int	prev;
	int	pos_max;
	int	pos_prev;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max = get_max_index(*b);
		prev = max - 1;
		pos_max = get_pos(*b, max);
		pos_prev = get_pos(*b, prev);
		if (
			pos_prev != -1 && get_cost(pos_prev, size)
			< get_cost(pos_max, size)
		)
			tmp_push(a, b, max, pos_prev);
		else
		{
			optimal_rotate(b, pos_max);
			pa(a, b, 1);
		}
	}
}
