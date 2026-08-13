#include "push_swap.h"

void    organize_stack(t_stack *stack_a)
{
    int     i;
    t_node  *tmp;
    t_node  *min_node;

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

void    sort_chunks(t_stack *stack_a, t_stack *stack_b, t_config *config)
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
        push_chunk(stack_a, stack_b, start, end, config);
        start = end + 1;
    }
}

void    push_back(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
    int max_index;

    while (stack_b->size > 0)
    {
        max_index = stack_b->size - 1;
        rotate_b_to_top(stack_b, max_index, config);
        pa(stack_a, stack_b, config);
    }
}

void    chunk_sort(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
    organize_stack(stack_a);
    sort_chunks(stack_a, stack_b, config);
    push_back(stack_a, stack_b, config);

}
