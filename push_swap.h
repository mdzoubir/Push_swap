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

// Stack Operations
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

#endif