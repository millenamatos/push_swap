/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:45:07 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/10 23:46:19 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack_a)
{
	t_node	*current;
	t_node	*next_one;
	double	mistakes;
	double	total_pairs;

	if (!stack_a || !stack_a->top || stack_a->size < 2)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	current = stack_a->top;
	while (current)
	{
		next_one = current->next;
		while (next_one)
		{
			if (current->value > next_one->value)
				mistakes++;
			next_one = next_one->next;
			total_pairs++;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
