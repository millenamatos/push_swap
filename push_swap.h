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

typedef struct s_stack
{
	t_node 		*top;
	int			size;
}	t_stack;

t_node	*create_node(int value);
void	stack_add_back(t_node **stack, t_node *new_node);
void	parse_args(int argc, char **argv, t_node **stack);
int		ft_atoi(const char *str);
void 	sa(t_stack *stack_a);
void 	sb(t_stack *stack_b);
void 	ss(t_stack *stack_a, t_stack *stack_b);
void 	pa(t_stack *stack_a, t_stack *stack_b);
void 	pb(t_stack *stack_a, t_stack *stack_b);
void 	ra(t_stack *stack_a);
void 	rb(t_stack *stack_b);
void 	rr(t_stack *stack_a, t_stack *stack_b);
void 	rra(t_stack *stack_a);
void 	rrb(t_stack *stack_b);
void 	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
