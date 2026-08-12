/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:55:08 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/11 22:36:11 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	return (1);
}

void	sa(t_stack *stack_a, t_config *config)
{
	if (!do_swap(stack_a))
		return ;
	if (config)
	{
		config->count_sa++;
		config->count_total++;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, t_config *config)
{
	if (!do_swap(stack_b))
		return ;
	if (config)
	{
		config->count_sb++;
		config->count_total++;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = do_swap(stack_a);
	swapped_b = do_swap(stack_b);
	if (!swapped_a && !swapped_b)
		return ;
	if (config)
	{
		config->count_ss++;
		config->count_total++;
	}
	write(1, "ss\n", 3);
}
