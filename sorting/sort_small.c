/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:07:59 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:38:12 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_min(t_node **stack_a, t_node **stack_b)
{
	int	index;
	int	size;

	index = get_min_pos(*stack_a);
	size = stack_size(*stack_a);
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		while (index++ < size)
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
}

void	sort_two(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

void    sort_three(t_node **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->index;
    b = (*stack)->next->index;
    c = (*stack)->next->next->index;
    if (a > b && b < c && a < c)
        sa(stack, 1);
    else if (a > b && b > c)
    {
        sa(stack, 1);
        rra(stack, 1);
    }
    else if (a > b && b < c && a > c)
        ra(stack, 1);
    else if (a < b && b > c && a < c)
    {
        sa(stack, 1);
        ra(stack, 1);
    }
    else if (a < b && b > c && a > c)
        rra(stack, 1);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	push_min(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_min(stack_a, stack_b);
	push_min(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
