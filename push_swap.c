#include "includes/push_swap.h"

int main(int ac, char **av)
{
	t_node *stack_a;
	t_node *stack_b;
	int size;

	if (ac < 2)
		return (0);

	stack_a = NULL;
	stack_b = NULL;

	parse_args(ac, av, &stack_a);

	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);

	size = stack_size(stack_a);
	assign_index(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		push_chunks(&stack_a, &stack_b);
		push_back_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
