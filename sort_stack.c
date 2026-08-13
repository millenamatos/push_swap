/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 21:08:02 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/13 18:48:53 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		i;

	current = a->top;
	min_val = current->value;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	push_min_to_b(t_stack *a, t_stack *b, t_config *config)
{
	int	pos;
	int	i;

	pos = find_min_pos(a);
	if (pos <= a->size / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(a, config);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < a->size - pos)
		{
			rra(a, config);
			i++;
		}
	}
	pb(a, b, config);
}

void	sort_three(t_stack *a, t_config *config)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a, config);
	else if (top > mid && mid > bot)
	{
		sa(a, config);
		rra(a, config);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, config);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, config);
		ra(a, config);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, config);
}

void	sort_small(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size == 2)
	{
		sa(a, config);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, config);
		return ;
	}
	while (a->size > 3)
		push_min_to_b(a, b, config);
	sort_three(a, config);
	while (b->size > 0)
		pa(a, b, config);
}

void	sort_stack(t_stack *a, t_stack *b, t_config *config, double disorder)
{
	if (a->size <= 5 && (config->strategy == STRATEGY_ADAPTIVE
			|| config->strategy == STRATEGY_SIMPLE))
	{
		config->strategy = STRATEGY_SIMPLE;
		sort_small(a, b, config);
		return ;
	}
	if (config->strategy == STRATEGY_ADAPTIVE)
	{
		if (disorder < 0.2)
			config->strategy = STRATEGY_SIMPLE;
		else if (disorder < 0.5)
			config->strategy = STRATEGY_MEDIUM;
		else
			config->strategy = STRATEGY_COMPLEX;
	}
	if (config->strategy == STRATEGY_SIMPLE)
		selection_sort(a, b, config);
	else if (config->strategy == STRATEGY_MEDIUM)
		chunk_sort(a, b, config);
	else if (config->strategy == STRATEGY_COMPLEX)
		radix_sort(a, b, config);
}
