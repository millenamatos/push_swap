/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:35:54 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/07/24 11:33:09 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
{
	int	signal;
	int	result;

	signal = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * signal);
}

void	parse_args(int argc, char **argv, t_node **stack)
{
	int		i;
	int		val;
	t_node	*new_node;

	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		new_node = create_node(val);
		if (!new_node)
			return ;
		stack_add_back(stack, new_node);
		i++;
	}
}
