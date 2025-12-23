#include "../push_swap.h"

void optimal_rotate(t_node **stack, int pos)
{
	int size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(stack);
	}
	else
	{
		while (pos++ < size)
			rrb(stack);
	}
}

static int get_chunk_value(t_node *a)
{
	int size;

	size = stack_size(a);
	if (size <= 10)
		return (1);
	else if (size <= 100)
		return (4);
	else
		return (10);
}

void push_chunks(t_node **a, t_node **b)
{
	int size;
	int chunk_size;
	int i;

	size = stack_size(*a);
	chunk_size = size / get_chunk_value(*a);
	if (size % get_chunk_value(*a))
		chunk_size++;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

static void	tmp_push(t_node **a, t_node **b, int max, int pos_prev)
{
	optimal_rotate(b, pos_prev);
	pa(a, b);
	optimal_rotate(b, get_pos(*b, max));
	pa(a, b);
	sa(a);
}

void push_back_to_a(t_node **a, t_node **b)
{
	int max;
	int prev;
	int pos_max;
	int pos_prev;
	int size;

	while (*b)
	{
		size = stack_size(*b);
		max = get_max_index(*b);
		prev = max - 1;
		pos_max = get_pos(*b, max);
		pos_prev = get_pos(*b, prev);
		if (pos_prev != -1 && get_cost(pos_prev, size) < get_cost(pos_max, size))
			tmp_push(a, b, max, pos_prev);
		else
		{
			optimal_rotate(b, pos_max);
			pa(a, b);
		}
	}
}
