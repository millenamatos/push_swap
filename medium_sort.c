#include "push_swap.h"

void    organize_stack(t_stack *stack_a)
{
    int     i;
    t_node  *tmp;
    t_node  *min_node;

    tmp = stack_a->top;
    while (tmp)
    {
        tmp->index = -1;
        tmp = tmp->next;
    }

    i = 0;
    while(i < stack_a->size)
    {
        min_node = NULL;
        tmp = stack_a->top;

        while (tmp)
        {
            if (tmp->index == -1)
            {
                if (min_node == NULL || tmp->value < min_node->value)
                    min_node = tmp;
            }
            tmp = tmp->next;
        }
        min_node->index = i;
        i++;
    }
}

void    sort_chunks(t_stack *stack_a, t_stack *stack_b)
{
    int start;
    int end;
    int chunk_size;
    int size;
    
    size = stack_a->size;
    chunk_size = get_chunk_size(stack_a->size);
    start = 0;
    while (start < size)
    {
        end = start + chunk_size - 1;
        if (end >= size)
            end = size - 1;
        push_chunk(stack_a, stack_b, start, end);
        start = end + 1;
    }
}

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