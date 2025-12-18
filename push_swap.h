#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_node
{
	int				value;
	int				index;
	struct s_node	*next;
} t_node;

// Function for node init
t_node	*new_node(int content);
void	add_node_back(t_node **lst, t_node *new);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);

// Swap
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);


// Push
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);

// rotate 
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// reverse rotate 
void reverse_rotate(t_node **stack);
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

// utils
char	**ft_split(char const *s, char c);

#endif