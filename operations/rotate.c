/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <mzoubir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:45:30 by mzoubir           #+#    #+#             */
/*   Updated: 2025/12/28 21:06:22 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	ra(t_node **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}
