/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:43:57 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/12 21:00:24 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_config	config;
	double		disorder;

	if (argc < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_config(&config);
	parse_args(argc, argv, &stack_a, &config);
	if (stack_a.size == 0)
		return (0);
	disorder = compute_disorder(&stack_a);
	if (disorder > 0.0)
		sort_stack(&stack_a, &stack_b, &config, disorder);
	if (config.bench)
		print_bench(&config, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
