/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:38:35 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:33:46 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_instruction(char *line)
{
	return (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n") || !ft_strcmp(line, "pa\n")
		|| !ft_strcmp(line, "pb\n") || !ft_strcmp(line, "ra\n")
		|| !ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n")
		|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"));
}

void	get_operations(t_node **a, t_node **b, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa\n"))
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
}

void	read_and_execute(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line();
	while (line != NULL)
	{
		if (!is_valid_instruction(line))
		{
			free(line);
			write(1, "Error\n", 6);
			exit(1);
		}
		get_operations(a, b, line);
		free(line);
		line = get_next_line();
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	parse_args(ac, av, &a);
	read_and_execute(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}
