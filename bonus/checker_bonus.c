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

static void	error(t_node **a, t_node **b, char *line)
{
	if (line)
		free(line);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_node **a, t_node **b, char *line)
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

static void	read_and_execute(t_node **a, t_node **b)
{
	char	*line;
	t_ope	*lst;
	t_ope	*tmp;

	lst = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!is_valid_instruction(line))
		{
			free_cmd_list(&lst);
			error(a, b, line);
		}
		add_cmd_back(&lst, line);
		line = get_next_line(0);
	}
	tmp = lst;
	while (tmp)
	{
		parse_command(a, b, tmp->line);
		tmp = tmp->next;
	}
	free_cmd_list(&lst);
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
