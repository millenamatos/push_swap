/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:53:01 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/13 13:30:44 by mmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	organize_stack(t_stack *stack_a)
{
	int		i;
	t_node	*tmp;
	t_node	*min_node;

	i = 0;
	while (i < stack_a->size)
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

void	push_back(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	int	max_index;

	while (stack_b->size > 0)
	{
		max_index = stack_b->size - 1;
		rotate_b_to_top(stack_b, max_index, config);
		pa(stack_a, stack_b, config);
	}
}

int	find_position(t_stack *stack_a, int index)
{
	int			position;
	t_node		*tmp;

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

void	chunk_sort(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	int	start;
	int	end;
	int	chunk_size;
	int	size;
	int	index;

	organize_stack(stack_a);
	size = stack_a->size;
	chunk_size = get_chunk_size(stack_a->size);
	start = 0;
	while (start < size)
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		while (has_chunk(stack_a, start, end))
		{
			index = find_chunk_index(stack_a, start, end);
			rotate_to_top(stack_a, index, config);
			pb(stack_a, stack_b, config);
		}
		start = end + 1;
	}
	push_back(stack_a, stack_b, config);
}
