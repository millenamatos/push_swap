/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:20:33 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/10 18:08:24 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		config->strategy = 0;
	else if (ft_strcmp(arg, "--simple") == 0)
		config->strategy = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		config->strategy = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		config->strategy = 3;
	else if (ft_strcmp(arg, "--bench") == 0)
		config->bench = 1;
	else
		return (0);
	return (1);
}
