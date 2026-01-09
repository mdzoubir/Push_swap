/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:44:25 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:36:18 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_node **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
