#include "push_swap.h"

int is_valid_number(char *str)
{
	int i;

	if (!str)
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

int ft_atoi(const char *nptr, int *out)
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
		return 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return 0;
		i++;
	}

	*out = (int)(result * sign);
	return 1;
}

void	free_list(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i]);
	free(str);
}

int	validate_input(char **av)
{
	int **numbers;
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		numbers = ft_split(av[i], ' ');
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				free_list(numbers);
			free(numbers[j++]);
		}
		free(numbers);

		i++;
	}
	return (1);
}

void parse_args(int ac, char **av, t_node **stack_a)
{
    char **args;
    int value;
    int i;
	int j;

	i = 0;
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        j = 0;
        while (args[j])
        {
            if (!is_valid_number(args[j]) || !ft_atoi(args[j], &value))
            {
                free_numbers(args);
                write(2, "Error\n", 6);
                exit(1);
            }

            // TODO: check duplicates here
            add_node_back(stack_a, new_node(value));
            free(args[j]);
            j++;
        }
        free(args);
		i++;
    }
}
