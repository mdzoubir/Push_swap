/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <mzoubir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:12:41 by mzoubir           #+#    #+#             */
/*   Updated: 2025/12/28 21:12:43 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void optimal_rotate(t_node **stack, int pos)
{
	int size;

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

static int get_chunk_value(t_node *a)
{
    int size;

    size = stack_size(a);
    if (size <= 10)
        return (3);
    else if (size <= 100)
        return (5);
    else
        return (15);
}

void    get_closest_node(t_node **a, int max)
{
    t_node  *tmp;
    int     first_match;
    int     last_match;
    int     best_pos;

    tmp = *a;
    first_match = -1;
    last_match = -1;
    
    int i = 0;
    while (tmp)
    {
        if (tmp->index <= max)
        {
            if (first_match == -1)
                first_match = i;
            last_match = i;
        }
        tmp = tmp->next;
        i++;
    }
    if (first_match != -1)
    {
        if (first_match <= (stack_size(*a) - last_match))
            while (first_match-- > 0)
                ra(a, 1);
        else
        {
            best_pos = stack_size(*a) - last_match;
            while (best_pos-- > 0)
                rra(a, 1);   
        }   
    }
}

void push_chunks(t_node **a, t_node **b)
{
    int size;
    int chunk_size;
    int i;

    size = stack_size(*a);
    chunk_size = size / get_chunk_value(*a);
    if (size % get_chunk_value(*a))
        chunk_size++;
    i = 0;
    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b, 1);
            rb(b, 1);
            i++;
        }
        else if ((*a)->index <= i + chunk_size)
        {
            pb(a, b, 1);
            i++;
        }
        else
            get_closest_node(a, i + chunk_size);
    }
}

static void tmp_push(t_node **a, t_node **b, int max, int pos_prev)
{
	optimal_rotate(b, pos_prev);
	pa(a, b, 1);
	optimal_rotate(b, get_pos(*b, max));
	pa(a, b, 1);
	sa(a, 1);
}

void push_back_to_a(t_node **a, t_node **b)
{
	int max;
	int prev;
	int pos_max;
	int pos_prev;
	int size;

	while (*b)
	{
		size = stack_size(*b);
		max = get_max_index(*b);
		prev = max - 1;
		pos_max = get_pos(*b, max);
		pos_prev = get_pos(*b, prev);
		if (pos_prev != -1 && get_cost(pos_prev, size) < get_cost(pos_max,
																  size))
			tmp_push(a, b, max, pos_prev);
		else
		{
			optimal_rotate(b, pos_max);
			pa(a, b, 1);
		}
	}
}
