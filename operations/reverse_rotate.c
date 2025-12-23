#include "../push_swap.h"

static int reverse_rotate(t_node **stack)
{
    t_node *last;
    t_node *before_last;
    
    if (!stack || !*stack || !(*stack)->next)
        return (0);
    before_last = *stack;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *stack;
    *stack = last;
    return (1);
}

void rra(t_node **stack_a)
{
    if (reverse_rotate(stack_a))
        write(1, "rra\n", 4);
}

void rrb(t_node **stack_b)
{
    if (reverse_rotate(stack_b))
        write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    int a = reverse_rotate(stack_a);
    int b = reverse_rotate(stack_b);
    if (a && b)
        write(1, "rrr\n", 4);
}