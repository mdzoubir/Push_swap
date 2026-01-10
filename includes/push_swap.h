/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:15:23 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:37:15 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// libft
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);

// Function for node init
t_node				*new_node(int content);
void				add_node_back(t_node **lst, t_node *new);
void				free_stack(t_node **stack);
int					stack_size(t_node *stack);

// Swap
void				sa(t_node **stack_a, int print);
void				sb(t_node **stack_b, int print);
void				ss(t_node **stack_a, t_node **stack_b, int print);

// Push
void				pa(t_node **stack_a, t_node **stack_b, int print);
void				pb(t_node **stack_a, t_node **stack_b, int print);

// rotate
void				ra(t_node **stack_a, int print);
void				rb(t_node **stack_b, int print);
void				rr(t_node **stack_a, t_node **stack_b, int print);

// reverse rotate
void				rra(t_node **stack_a, int print);
void				rrb(t_node **stack_b, int print);
void				rrr(t_node **stack_a, t_node **stack_b, int print);

// utils
int					is_sorted(t_node *stack);

// helpres
void				print_error(void);
void				free_split(char **str);
int					get_min_index(t_node *stack);
void				handle_error(char **args, t_node **stack_a);

// Parsing
void				parse_args(int ac, char **av, t_node **stack_a);

// Sorting functions
void				sort_two(t_node **stack_a);
void				sort_three(t_node **stack_a);
void				sort_four(t_node **stack_a, t_node **stack_b);
void				sort_five(t_node **stack_a, t_node **stack_b);

// Helper functions
int					get_max_index(t_node *stack);
int					get_pos(t_node *stack, int index);
int					get_cost(int pos, int size);
int					get_chunk_value(t_node *a);

// Sorting
void				push_chunks(t_node **a, t_node **b);
void				push_back_to_a(t_node **a, t_node **b);
void				assign_index(t_node *stack);

#endif
