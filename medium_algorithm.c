#include "push_swap.h"

<<<<<<< HEAD
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
=======
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

void    rotate_to_top(t_stack *stack_a, int index)
>>>>>>> 08be0884a8d7cd1469f28acd25efdc2006b29261
{
    int i;
    int position;

<<<<<<< HEAD
    position = find_position(stack_b, index);
    if (position <= stack_b->size / 2)
=======
    position = find_position(stack_a, index);
    if (position <= stack_a->size / 2)
>>>>>>> 08be0884a8d7cd1469f28acd25efdc2006b29261
    {
        i = 0;
        while (i < position)
        {
<<<<<<< HEAD
            rb(stack_b);
=======
            ra(stack_a);
>>>>>>> 08be0884a8d7cd1469f28acd25efdc2006b29261
            i++;
        }
    }
    else
    {
        i = 0;
<<<<<<< HEAD
        while (i < stack_b->size - position)
        {
            rrb(stack_b);
            i++;
        }
    }
}
=======
        while (i < stack_a->size - position)
        {
            rra(stack_a);
            i++;
        }
    }
}

>>>>>>> 08be0884a8d7cd1469f28acd25efdc2006b29261
