/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:13:11 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/05 19:15:34 by mmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack || stack->size == 0)
		return (NULL);
	current = stack->top;
	min_node = stack->top;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	t_node	*min_node;

	if (stack_a->size < 2)
		return ;
	while (stack_a->size > 0)
	{
		min_node = find_min(stack_a);
		while (stack_a->top != min_node)
			ra(stack_a, config);
		pb(stack_a, stack_b, config);
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b, config);
}
