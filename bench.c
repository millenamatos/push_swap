/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:42:47 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/11 19:52:37 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	double	percent;
	int		int_part;
	int		dec_part;

	percent = disorder * 100.0;
	int_part = (int)percent;
	dec_part = (int)((percent - int_part) * 100.0 + 0.5);
	if (dec_part >= 100)
	{
		int_part++;
		dec_part = 0;
	}
	ft_dprintf(2, "[bench] Disorder: %d.", int_part);
	if (dec_part < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", dec_part);
}

static void	print_ops_details(t_config *config)
{
	ft_dprintf(2, "[bench] Total ops: %d\n", config->count_total);
	ft_dprintf(2, "[bench] sa: %d, sb: %d, ss: %d\n",
		config->count_sa, config->count_sb, config->count_ss);
	ft_dprintf(2, "[bench] pa: %d, pb: %d\n",
		config->count_pa, config->count_pb);
	ft_dprintf(2, "[bench] ra: %d, rb: %d, rr: %d\n",
		config->count_ra, config->count_rb, config->count_rr);
	ft_dprintf(2, "[bench] rra: %d, rrb: %d, rrr: %d\n",
		config->count_rra, config->count_rrb, config->count_rrr);
}

void	print_bench(t_config *config, double mess, char *strat, char *complx)
{
	if (!config || !config->bench)
		return ;
	print_disorder(mess);
	ft_dprintf(2, "[bench] Strategy: %s (%s)\n", strat, complx);
	print_ops_details(config);
}
