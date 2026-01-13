/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:14:24 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/13 16:29:20 by mzoubir          ###   ########.fr       */
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

void				sa(t_node **stack_a, int print);
void				sb(t_node **stack_b, int print);
void				ss(t_node **stack_a, t_node **stack_b, int print);

void				pa(t_node **stack_a, t_node **stack_b, int print);
void				pb(t_node **stack_a, t_node **stack_b, int print);

void				ra(t_node **stack_a, int print);
void				rb(t_node **stack_b, int print);
void				rr(t_node **stack_a, t_node **stack_b, int print);

void				rra(t_node **stack_a, int print);
void				rrb(t_node **stack_b, int print);
void				rrr(t_node **stack_a, t_node **stack_b, int print);

int					is_sorted(t_node *stack);
int					stack_size(t_node *stack);
void				free_stack(t_node **stack);

char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*get_next_line(void);

#endif
