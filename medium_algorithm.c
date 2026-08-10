#include "push_swap.h"

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

int    get_chunk_size(int size)
{
    if (size <= 100)
        return (20);
    return (45);
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

int		find_max_index(t_stack *stack_b)
{
	t_node *tmp;
	int max;

	tmp = stack_b->top;
	max = -1;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void    rotate_b_to_top(t_stack *stack_b, int index)
{
    int i;
    int position;

    position = find_position(stack_b, index);
    if (position <= stack_b->size / 2)
    {
        i = 0;
        while (i < position)
        {
            rb(stack_b);
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < stack_b->size - position)
        {
            rrb(stack_b);
            i++;
        }
    }
}