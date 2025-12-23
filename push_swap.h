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

// libft
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

// Function for node init
t_node	*new_node(int content);
void	add_node_back(t_node **lst, t_node *new);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);

// Swap
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);


// Push
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);

// rotate 
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// reverse rotate 
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

// utils
int is_sorted(t_node *stack);

// Errors 
void print_error(void);

// Parsing
void parse_args(int ac, char **av, t_node **stack_a);

// Sorting functions
void sort_two(t_node **stack_a);
void sort_three(t_node **stack_a);
void sort_four(t_node **stack_a, t_node **stack_b);
void sort_five(t_node **stack_a, t_node **stack_b);





// Helper functions
int		get_max_index(t_node *stack);
int		get_pos(t_node *stack, int index);
int		get_cost(int pos, int size);

// Sorting
void	push_chunks(t_node **a, t_node **b);
void	push_back_to_a(t_node **a, t_node **b);
void	assign_index(t_node *stack);

#endif