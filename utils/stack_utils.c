/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:13:45 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:39:03 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new;
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	free_stack(t_node **stack)
{
	t_node	*node;

	if (!stack)
		return ;
	while (*stack)
	{
		node = (*stack)->next;
		free(*stack);
		*stack = node;
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
