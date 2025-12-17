#include "../push_swap.h"

void pa(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;

    if (!stack_b || !*stack_b)
        return;

    tmp = *stack_b;
    *stack_b = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;

    if (!stack_a || !*stack_a)
        return;

    tmp = *stack_a;
    *stack_a = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}