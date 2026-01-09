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

int	get_min_index(t_node *stack)
{
	int	min;
	int	index;
	int	i;

	min = stack->value;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	handle_error(char **args, t_node **stack_a)
{
	if (args)
		free_split(args);
	free_stack(stack_a);
	print_error();
}

void	print_error(void)
{
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
