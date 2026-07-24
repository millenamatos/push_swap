/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:07:28 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/07/24 11:33:45 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

t_node	*create_node(int value);
void	stack_add_back(t_node **stack, t_node *new_node);
void	parse_args(int argc, char **argv, t_node **stack);
int		ft_atoi(const char *str);

#endif
