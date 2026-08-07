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

