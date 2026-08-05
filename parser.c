/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:35:54 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/05 07:10:17 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str, int *error)
{
	int		signal;
	long	result;

	signal = 1;
	result = 0;
	*error = 0;
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
		if ((result * signal) > 2147483647 || (result * signal) < -2147483648)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return (result * signal);
}

int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_node **stack)
{
	int		i;
	int		val;
	t_node	*new_node;

	if (!is_valid_number(argc, argv))
		return ;
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
