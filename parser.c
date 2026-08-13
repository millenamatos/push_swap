/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:20:33 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/12 22:33:17 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_config(t_config *config)
{
	config->strategy = 0;
	config->bench = 0;
	config->count_sa = 0;
	config->count_sb = 0;
	config->count_ss = 0;
	config->count_pa = 0;
	config->count_pb = 0;
	config->count_ra = 0;
	config->count_rb = 0;
	config->count_rr = 0;
	config->count_rra = 0;
	config->count_rrb = 0;
	config->count_rrr = 0;
	config->count_total = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	parse_flag(char *arg, t_config *config)
{
	if (ft_strcmp(arg, "--adaptive") == 0)
		config->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strcmp(arg, "--simple") == 0)
		config->strategy = STRATEGY_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		config->strategy = STRATEGY_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		config->strategy = STRATEGY_COMPLEX;
	else if (ft_strcmp(arg, "--bench") == 0)
		config->bench = 1;
	else
		return (0);
	return (1);
}

void	parse_args(int argc, char **argv, t_stack *stack, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!parse_flag(argv[i], config))
				free_error_exit(stack, NULL);
		}
		else
			parse_number(argv[i], stack);
		i++;
	}
}
