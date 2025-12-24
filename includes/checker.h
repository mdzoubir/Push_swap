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


void parse_args(int ac, char **av, t_node **stack_a);
char	*get_next_line();

// Swap
void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b, int print);


// Push
void pa(t_node **stack_a, t_node **stack_b, int print);
void pb(t_node **stack_a, t_node **stack_b, int print);

// rotate 
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b, int print);

// reverse rotate 
void rra(t_node **stack_a, int print);
void rrb(t_node **stack_b, int print);
void rrr(t_node **stack_a, t_node **stack_b, int print);


int is_sorted(t_node *stack);



#endif