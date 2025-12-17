#include "../push_swap.h"

void rotate(t_node **stack)
{
	t_node *first;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return; 

	first = *stack;
    last = *stack;
	while (last->next)
        last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}