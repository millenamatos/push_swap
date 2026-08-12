#include "push_swap.h"

int    get_chunk_size(int size)
{
    int chunk_size;

    chunk_size = 1;
    while (chunk_size * chunk_size < size)
        chunk_size++;
    return (chunk_size);
}

void    push_chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int index;

    while (has_chunk(stack_a, start, end))
    {
        index = find_chunk_index(stack_a, start, end);
        rotate_to_top(stack_a, index);
        pb(stack_a, stack_b);
    }
}

int     has_chunk(t_stack *stack_a, int start, int end)
{
    t_node *tmp;

    tmp = stack_a->top;
    while (tmp)
    {
        if (tmp->index >= start && tmp->index <= end)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int find_chunk_index(t_stack *stack_a, int start, int end)
{
    t_node *tmp;

    tmp = stack_a->top;
    while (tmp)
    {
        if (tmp->index >= start && tmp->index <= end)
            return (tmp->index);
        tmp = tmp->next;
    }
    return (-1);
}

void    rotate_to_top(t_stack *stack_a, int index)
{
    int i;
    int position;

    position = find_position(stack_a, index);
    if (position <= stack_a->size / 2)
    {
        i = 0;
        while (i < position)
        {
            ra(stack_a);
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < stack_a->size - position)
        {
            rra(stack_a);
            i++;
        }
    }
}
