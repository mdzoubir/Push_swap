/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <mzoubir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:14:24 by mzoubir           #+#    #+#             */
/*   Updated: 2025/12/28 21:56:58 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

void				parse_args(int ac, char **av, t_node **stack_a);
char				*get_next_line(void);

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

int					is_sorted(t_node *stack);
void				free_stack(t_node **stack);

// gnl
char				*ft_save_extra(char *stash);
char				*ft_get_line(char *stash);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*get_next_line(void);
#endif
