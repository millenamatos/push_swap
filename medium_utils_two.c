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