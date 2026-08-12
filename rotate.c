/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:55:29 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/11 22:57:47 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_stack *stack_a, t_config *config)
{
	if (!do_rotate(stack_a))
		return ;
	if (config)
	{
		config->count_ra++;
		config->count_total++;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, t_config *config)
{
	if (!do_rotate(stack_b))
		return ;
	if (config)
	{
		config->count_rb++;
		config->count_total++;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = do_rotate(stack_a);
	rotated_b = do_rotate(stack_b);
	if (!rotated_a && !rotated_b)
		return ;
	if (config)
	{
		config->count_rr++;
		config->count_total++;
	}
	write(1, "rr\n", 3);
}
