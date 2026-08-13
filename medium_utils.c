/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:03:05 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/13 13:06:32 by mmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

int	has_chunk(t_stack *stack_a, int start, int end)
{
	t_node	*tmp;

	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_chunk_index(t_stack *stack_a, int start, int end)
{
	t_node	*tmp;

	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

void	rotate_to_top(t_stack *stack_a, int index, t_config *config)
{
	int	i;
	int	position;

	position = find_position(stack_a, index);
	if (position <= stack_a->size / 2)
	{
		i = 0;
		while (i < position)
		{
			ra(stack_a, config);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack_a->size - position)
		{
			rra(stack_a, config);
			i++;
		}
	}
}

void	rotate_b_to_top(t_stack *stack_b, int index, t_config *config)
{
	int	i;
	int	position;

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
