/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:52:46 by mmatos-d          #+#    #+#             */
/*   Updated: 2026/08/13 13:10:29 by mmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_max_bits(t_stack *stack_a)
{
	int	max_index;
	int	bits;

	max_index = stack_a->size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	int	bit;
	int	i;
	int	size;
	int	max_bits;

	organize_stack(stack_a);
	max_bits = get_max_bits(stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		size = stack_a->size;
		i = 0;
		while (i < size)
		{
			if (((stack_a->top->index >> bit) & 1) == 0)
				pb(stack_a, stack_b, config);
			else
				ra(stack_a, config);
			i++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b, config);
		bit++;
	}
}
