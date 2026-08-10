#include "push_swap.h"

void    push_back(t_stack *stack_a, t_stack *stack_b)
{
    int max_index;

    while (stack_b->size > 0)
    {
        max_index = find_max_index(stack_b);
        rotate_b_to_top(stack_b, max_index);
        pa(stack_a, stack_b);
    }
}