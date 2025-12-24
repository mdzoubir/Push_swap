#include "../includes/push_swap.h"

static int get_min_index(t_node *stack)
{
    int min;
    int index;
    int i;

    min = stack->value;
    index = 0;
    i = 0;
    while (stack)
    {
        if (stack->value < min)
        {
            min = stack->value;
            index = i;
        }
        stack = stack->next;
        i++;
    }
    return (index);
}

static void push_min(t_node **stack_a, t_node **stack_b)
{
    int index;
    int size;

    index = get_min_index(*stack_a);
    size = stack_size(*stack_a);

    if (index < size / 2)
    {
        while (index > 0)
        {
            ra(stack_a, 1);
            index--;
        }
    }
    else
    {
        while (index < size)
        {
            rra(stack_a, 1);
            index++;
        }
    }
    pb(stack_a, stack_b, 1);
}


void sort_two(t_node **stack)
{
    if ((*stack)->value > (*stack)->next->value)
        sa(stack, 1);
}

void sort_three(t_node **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;

    if (a > b && b < c && a < c)
        sa(stack, 1);
    else if (a > b && b > c)
    {
        sa(stack, 1);
        rra(stack, 1);
    }
    else if (a > b && b < c && a > c)
        ra(stack, 1);
    else if (a < b && b > c && a < c)
    {
        sa(stack, 1);
        ra(stack, 1);
    }
    else if (a < b && b > c && a > c)
        rra(stack, 1);
}

void sort_four(t_node **stack_a, t_node **stack_b)
{
    push_min(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b, 1);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    push_min(stack_a, stack_b);
    push_min(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b, 1);
    pa(stack_a, stack_b, 1);
}
