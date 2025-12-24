#include "includes/push_swap.h"

static int is_valid_number(char *str)
{
	int i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int ft_atoi(const char *nptr, int *out)
{
	long result;
	int sign;
	int i;

	result = 0;
	i = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!nptr[i])
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}

static void free_split(char **str)
{
	int i;

	if (!str)
		return;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
static void handle_error(char **args, t_node **stack_a)
{
	if (args)
		free_split(args);
	free_stack(stack_a);
	print_error();
}
static int process_string(char *str, t_node **stack_a)
{
	int value;

	if (!is_valid_number(str))
		return (0);
	if (!ft_atoi(str, &value))
		return (0);
	if (has_duplicate(*stack_a, value))
		return (0);
	add_node_back(stack_a, new_node(value));
	return (1);
}
void parse_args(int ac, char **av, t_node **stack_a)
{
	char **args;
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args || !args[0])
			handle_error(args, stack_a);
		j = 0;
		while (args[j])
		{
			if (!process_string(args[j++], stack_a))
				handle_error(args, stack_a);
		}
		free_split(args);
		i++;
	}
}