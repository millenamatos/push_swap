#include "push_swap.h"

int    find_position(t_stack *stack_a, int index)
{
    int     position;
    t_node *tmp;

    position = 0;
    tmp = stack_a->top;

    while (tmp)
    {
        if (tmp->index == index)
            return (position);
        position++;
        tmp = tmp->next;
    }
    return (-1);
}

void    rotate_b_to_top(t_stack *stack_b, int index, t_config *config)
{
    int i;
    int position;

    position = find_position(stack_b, index);
    if (position <= stack_b->size / 2)
    {
        i = 0;
        while (i < position)
        {
            rb(stack_b, config);
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < stack_b->size - position)
        {
            rrb(stack_b, config);
            i++;
        }
    }
}