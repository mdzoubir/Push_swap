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

#include "../includes/checker_bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	error(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	parse_command(t_node **a, t_node **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static void	read_and_execute(t_node **a, t_node **b)
{
	char	*line;
	int		error_flag;

	error_flag = 0;
	line = get_next_line();
	while (line != NULL)
	{
		if (!error_flag && !parse_command(a, b, line))
			error_flag = 1;
		free(line);
		line = get_next_line();
	}
	if (error_flag)
		error(a, b);
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
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
