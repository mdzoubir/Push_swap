#include "../includes/push_swap.h"

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

void	sa(t_node **stack_a, int print)
{
	swap(stack_a);
    if (print)
        write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, int print)
{
	swap(stack_b);
    if (print)
        write(1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b, int print)
{
    swap(stack_a);
    swap(stack_b);
    if (print)
        write(1, "ss\n", 3);
}