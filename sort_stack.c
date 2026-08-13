/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 21:08:02 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/12 22:56:33 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b, t_config *config, double disorder)
{
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
