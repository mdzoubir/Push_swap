/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:57:55 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:38:40 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_pos(t_node *stack)
{
	int	min_rank;
	int	min_pos;
	int	current_pos;

	if (!stack)
		return (-1);
	min_rank = stack->index;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->index < min_rank)
		{
			min_rank = stack->index;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

void	handle_error(char **args, t_node **stack_a)
{
	if (args)
		free_split(args);
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
