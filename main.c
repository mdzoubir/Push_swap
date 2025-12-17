#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

t_node *parse_input(int argc, char **argv);

void sa(t_node **stack_a);
void pb(t_node **stack_a, t_node **stack_b);

void sort_three(t_node **stack_a);
void sort_five(t_node **stack_a, t_node **stack_b);
void radix_sort(t_node **stack_a, t_node **stack_b);

int is_sorted(t_node *stack);
void free_stack(t_node **stack);

#endif