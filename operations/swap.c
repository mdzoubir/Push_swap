#include "../push_swap.h"

static int swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !*stack || !(*stack)->next)
        return (0);

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
    return (1);
}

void	sa(t_node **stack_a)
{
	if (swap(stack_a))
	    write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	if (swap(stack_b))
	    write(1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    int a = swap(stack_a);
    int b = swap(stack_b);
    if (a && b)
        write(1, "ss\n", 3);
}