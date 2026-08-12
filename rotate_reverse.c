/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:55:38 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/11 23:15:24 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_rev_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return (0);
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}

void	rra(t_stack *stack_a, t_config *config)
{
	if (!do_rev_rotate(stack_a))
		return ;
	if (config)
	{
		config->count_rra++;
		config->count_total++;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, t_config *config)
{
	if (!do_rev_rotate(stack_b))
		return ;
	if (config)
	{
		config->count_rrb++;
		config->count_total++;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	int	rev_a;
	int	rev_b;

	rev_a = do_rev_rotate(stack_a);
	rev_b = do_rev_rotate(stack_b);
	if (!rev_a && !rev_b)
		return ;
	if (config)
	{
		config->count_rrr++;
		config->count_total++;
	}
	write(1, "rrr\n", 4);
}
