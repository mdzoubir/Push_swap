#include "push_swap.h"
#include <stdio.h>

void	print_stack(char *name, t_node *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
void	test(void)
{
	t_node *a = NULL;
	t_node *b = NULL;

	add_node_back(&a, new_node(1));
	add_node_back(&a, new_node(2));
	add_node_back(&a, new_node(3));
	add_node_back(&a, new_node(4));

	print_stack("A", a);
	print_stack("B", b);

	sa(&a);
	print_stack("A after sa", a);

	pb(&a, &b);
	print_stack("A after pb", a);
	print_stack("B after pb", b);

	pa(&a, &b);
	print_stack("A after pa", a);
	print_stack("B after pa", b);

	ra(&a);
	print_stack("A after ra", a);

	rra(&a);
	print_stack("A after rra", a);

	sb(&b);
	rr(&a, &b);
	rrr(&a, &b);

	print_stack("A final", a);
	print_stack("B final", b);

	free_stack(&a);
	free_stack(&b);
}
int main(int ac, char **av)
{
    t_node *stack_a;

    if (ac < 2)
        return (0);
    stack_a = NULL;
    parse_args(ac, av, &stack_a);
    print_stack("A", stack_a);
	free_stack(&stack_a);
    return (0);
}
