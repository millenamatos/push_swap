/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 23:47:27 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/10 22:33:30 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->size = 0;
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_back(t_stack *stack, t_node *new_node)
{
	t_node	*last_node;

	if (!stack || !new_node)
		return ;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		last_node = stack->top;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	stack-size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	stack->top = NULL;
	size->size = 0;
}

void	push_to_stack(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}
