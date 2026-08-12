/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:55:19 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/11 22:10:44 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	t_node	*temp;

	if (!stack_b || stack_b->size == 0)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
	if (config)
	{
		config->count_pa++;
		config->count_total++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	t_node	*temp;

	if (!stack_a || stack_a->size == 0)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->size--;
	temp->next = stack_b->top;
	stack_b->top = temp;
	stack_b->size++;
	if (config)
	{
		config->count_pb++;
		config->count_total++;
	}
	write(1, "pb\n", 3);
}
